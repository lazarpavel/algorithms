#include "PercolationStats.h"

using namespace applications;

PercolationStats::PercolationStats(const uint n, const uint trials)
    : m_counts(trials, 0), m_trials(trials), m_size(n)
{
    run();
}

// perform trials independent experiments on an n-by-n grid
void PercolationStats::run()
{
    uint consumedTrials = 0;

    while (m_trials != consumedTrials)
    {
        uint counter = 0;

        Percolation percolation(m_size);

        while (!percolation.percolates())
        {
            uint row = std::experimental::randint(uint(0), m_size - 1);
            uint col = std::experimental::randint(uint(0), m_size - 1);

            if (!percolation.isOpen(row, col))
            {
                percolation.open(row, col);
                ++counter;
            }
        }

        m_counts[consumedTrials] = double(counter) / (m_size * m_size);
        ++consumedTrials;
    }
}

// sample mean of percolation threshold
double PercolationStats::mean() const
{
    double sum = 0;
    for (uint i = 0; i < m_counts.size(); ++ i)
        sum += m_counts[i];

    return double(sum) / m_counts.size();
}

// sample standard deviation of percolation threshold
double PercolationStats::standardDeviation() const
{
    if (m_counts.size() < 2)
        return 0;

    double average = mean();
    double sumSqDiff = 0.0;

    for (uint i = 0; i < m_counts.size(); ++i)
    {
        double diff = m_counts[i] - average;
        sumSqDiff += diff * diff;
    }

    return sqrt(sumSqDiff / (m_counts.size() - 1));
}

// low  endpoint of 95% confidence interval
double PercolationStats::confidenceLo() const
{
    return mean() - 1.96 * standardDeviation() / sqrt(m_trials);
}

// high endpoint of 95% confidence interval
double PercolationStats::confidenceHi() const
{
    return mean() + 1.96 * standardDeviation() / sqrt(m_trials);
}
