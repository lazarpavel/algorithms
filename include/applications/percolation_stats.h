#ifndef PERCOLATION_STATS_H
#define PERCOLATION_STATS_H

#include "percolation.h"

namespace applications
{
    class percolation_stats
    {
    public:
        percolation_stats(const unsigned int n, const unsigned int trials);

    public:
        double mean() const;
        double standard_deviation() const;
        double confidence_lo() const;
        double confidence_hi() const;

    private:
        void run();

    private:
        std::vector<double> m_counts;
        unsigned int m_trials;
        unsigned int m_size;
    };
}
#endif /* PERCOLATION_STATS_H */