#pragma once

#include <iostream>
#include <experimental/random>
#include <cmath>

#include "Percolation.h"

namespace applications
{
    class PercolationStats
    {
    public:
        PercolationStats(const uint n, const uint trials);

    public:
        double mean() const;
        double standardDeviation() const;
        double confidenceLo() const;
        double confidenceHi() const;

    private:
        void run();

    private:
        std::vector<double> m_counts;
        uint m_trials;
        uint m_size;
    };
}
