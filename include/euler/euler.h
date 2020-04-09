#pragma once

#include <string>

namespace interview
{
    class euler
    {
    public:
        int power_digit_sum(int power);
        int number_letter_counts(unsigned long long int number);

    private:
        std::string number_to_words(unsigned long long int number);
        std::string two_digit_number_to_words(unsigned int number, std::string suffix);
    };
}