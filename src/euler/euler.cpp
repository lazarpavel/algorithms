#include "euler/euler.h"
#include <algorithm>
#include <vector>

namespace interview
{
    int euler::power_digit_sum(int power)
    {
        std::vector<int> digits(500, 0);
        digits[0] = 1;

        for(size_t i = 0; i < power; ++i)
        {
            digits[0] = 2 * digits[0];

            for(int d = 1; d < 500; ++d)
                digits[d] = 2 * digits[d] + digits[d - 1] / 10;

            for(int d = 0; d < 500; ++d)
                digits[d] = digits[d] % 10;
        }

        int sum = 0;

        for(int d = 0; d < 500; ++d)
        {
            sum = sum + digits[d];
        }

        return sum;
    }

    int euler::number_letter_counts(unsigned long long int limit)
    {
        int sum = 0;

        for (unsigned long long int number = 1; number <= limit; ++number)
        {
            std::string words = number_to_words(number);

            words.erase(std::remove(words.begin(), words.end(), '-'), words.end());
            words.erase(std::remove(words.begin(), words.end(), ' '), words.end());

            sum += words.size();
        }

        return sum;
    }

    std::string euler::number_to_words(unsigned long long int number)
    {
        std::string result = two_digit_number_to_words(number % 100, "");

        if (number >= 100) {
            result = two_digit_number_to_words(((number / 100) % 10), " Hundred ") + (result.size() > 0 ? "and " : "") + result;
        }

        if (number >= 1000)
            result = two_digit_number_to_words(((number / 1000) % 100), " Thousand ") + result;

        if (number >= 100000)
            result = two_digit_number_to_words(((number / 100000) % 100), " Lakh, ") + result;

        if (number >= 10000000)
            result = two_digit_number_to_words((number / 10000000) % 100, " Crore, ") + result;

        if (number >= 1000000000)
            result = two_digit_number_to_words((number / 1000000000) % 100, " Billion, ") + result;

        return result;
    }

    std::string euler::two_digit_number_to_words(unsigned int number, std::string suffix)
    {
        const std::string BASIC[] = { std::string(), "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen " };
        const std::string TENS[] = { std::string(), std::string(), "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety " };

        if (!number)
        {
            return std::string();
        }

        if (number > 19)
        {
            return TENS[number / 10] + "-" + BASIC[number % 10] + suffix;
        }
        else
        {
            return BASIC[number] + suffix;
        }
    }

}