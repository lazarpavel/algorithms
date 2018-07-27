#pragma once

#include <iostream>
#include <experimental/random>
#include <cmath>

#include "percolation.h"

namespace applications
{
    class percolation_stats
    {
    public:
        percolation_stats(const uint n, const uint trials);

    public:
        double mean() const;
        double standard_deviation() const;
        double confidence_lo() const;
        double confidence_hi() const;

    private:
        void run();

    private:
        std::vector<double> m_counts;
        uint m_trials;
        uint m_size;
    };
}
