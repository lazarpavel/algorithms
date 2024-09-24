#pragma once

#include <algorithm>
#include <iterator>
#include <vector>

namespace algorithms
{
    // https://en.wikipedia.org/wiki/Euclidean_algorithm
    unsigned int gcd(unsigned int a, unsigned int b)
    {
        if (a == 0)
        {
            return b;
        }

        return gcd(b % a, a);
    }

    std::vector<unsigned> karatsuba_subtract(std::vector<unsigned> x, std::vector<unsigned> y)
    {
        int length = std::max(x.size(), y.size());

        while (x.size() < length)
        {
            x.insert(x.begin(), 0);
        }

        while (y.size() < length)
        {
            y.insert(y.begin(), 0);
        }

        std::vector<unsigned> result;

        for (int i = length - 1; i >= 0; --i)
        {
            int diff = x[i] - y[i];

            if (diff >= 0)
            {
                result.insert(result.begin(), diff);
            }
            else
            {
                // borrow from the previous column
                int j = i - 1;

                while (j >= 0)
                {
                    x[j] = (x[j] - 1) % 10;
                    if (x[j] != 9)
                    {
                        break;
                    }
                    else
                    {
                        j--;
                    }
                }

                result.insert(result.begin(), diff + 10);
            }
        }

        while (result.size() && result[0] == 0)
        {
            result.erase(result.begin(), result.begin() + 1);
        }

        return result;
    }

    std::vector<unsigned> karatsuba_add(std::vector<unsigned> x, std::vector<unsigned> y)
    {
        unsigned length = std::max(x.size(), y.size());

        while (x.size() < length)
        {
            x.insert(x.begin(), 0);
        }

        while (y.size() < length)
        {
            y.insert(y.begin(), 0);
        }

        std::vector<unsigned> result;

        unsigned carry = 0;
        for (int i = length - 1; i >= 0; --i)
        {
            unsigned same_column_sum = x[i] + y[i] + carry;
            carry = same_column_sum / 10;
            result.insert(result.begin(), same_column_sum % 10);
        }

        if (carry)
        {
            result.insert(result.begin(), carry);
        }

        while (result.size() && result[0] == 0)
        {
            result.erase(result.begin(), result.begin() + 1);
        }

        return result;
    }

    std::vector<unsigned> karatsuba_multiply(std::vector<unsigned> x, std::vector<unsigned> y)
    {
        unsigned length = std::max(x.size(), y.size());

        while (x.size() < length)
        {
            x.insert(x.begin(), 0);
        }

        while (y.size() < length)
        {
            y.insert(y.begin(), 0);
        }

        if (length == 1)
        {
            unsigned prod = x[0] * y[0];
            if (prod < 10) {
                return { prod };
            } else {
                return { prod / 10, prod % 10 };
            }
        }

        std::vector<unsigned> a(x.begin(), x.begin() + x.size() / 2);
        std::vector<unsigned> b(x.begin() + x.size() / 2, x.end());

        std::vector<unsigned> c(y.begin(), y.begin() + y.size() / 2);
        std::vector<unsigned> d(y.begin() + y.size() / 2, y.end());

        std::vector<unsigned> ac = karatsuba_multiply(a, c);
        std::vector<unsigned> bd = karatsuba_multiply(b, d);

        std::vector<unsigned> p = karatsuba_add(a, b);
        std::vector<unsigned> q = karatsuba_add(c, d);
        std::vector<unsigned> pq = karatsuba_multiply(p, q);

        std::vector<unsigned> adbc = karatsuba_subtract(pq, karatsuba_add(ac, bd));

        for (unsigned i = 0; i < length; ++i)
        {
            ac.push_back(0);
        }

        for (unsigned i = 0; i < length / 2; ++i)
        {
            adbc.push_back(0);
        }

        std::vector<unsigned> result = karatsuba_add(karatsuba_add(ac, bd), adbc);

        while (result.size() && result[0] == 0)
        {
            result.erase(result.begin(), result.begin() + 1);
        }

        return result;
    }

}
