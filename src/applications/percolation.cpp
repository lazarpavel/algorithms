#include <utility>

#include "percolation.h"

using namespace applications;

// create n-by-n grid, with all sites blocked
percolation::percolation(const uint n)
    : m_maze(n, std::vector<bool>(n, false)), m_size(n)
{
    // add 2 elements for virtual top and virtual bottom sites
    check_percolates_uf = std::make_shared<weighted_uf>(n * n + 2);
    check_full_uf = std::make_shared<weighted_uf>(n * n + 1);
}

// open site (row, col) if it is not open already
void percolation::open(uint row, uint col)
{
    if (row >= m_size)
        throw std::out_of_range("row out of range");
    if (col >= m_size)
        throw std::out_of_range("col out of range");

    m_maze[row][col] = true;

    if (row == 0)
    {
        check_percolates_uf->connect(0, col + 1);
        check_full_uf->connect(0, col + 1);
    }

    if (row == m_size - 1)
        check_percolates_uf->connect(m_size * m_size + 1, row * m_size + col + 1);

    if (row >= 1 && is_open(row - 1, col))
    {
        check_percolates_uf->connect(row * m_size + col + 1, (row - 1) * m_size + col + 1);
        check_full_uf->connect(row * m_size + col + 1, (row - 1) * m_size + col + 1);
    }

    if (row < (m_size - 1) && is_open(row + 1, col))
    {
        check_percolates_uf->connect(row * m_size + col + 1, (row + 1) * m_size + col + 1);

        if (row < m_size - 2)
            check_full_uf->connect(row * m_size + col + 1, (row + 1) * m_size + col + 1);
    }

    if (col >= 1 && is_open(row, col - 1))
    {
        check_percolates_uf->connect(row * m_size + col + 1, row * m_size + (col - 1) + 1);
        check_full_uf->connect(row * m_size + col + 1, row * m_size + (col - 1) + 1);
    }

    if (col < (m_size - 1) && is_open(row, col + 1))
    {
        check_percolates_uf->connect(row * m_size + col + 1, row * m_size + (col + 1) + 1);
        check_full_uf->connect(row * m_size + col + 1, row * m_size + (col + 1) + 1);
    }
}

// is site (row, col) open?
bool percolation::is_open(uint row, uint col) const
{
    if (row >= m_size)
        throw std::out_of_range("row out of range");
    if (col >= m_size)
        throw std::out_of_range("col out of range");

    return m_maze[row][col];
}

// is site (row, col) full?
bool percolation::is_full(uint row, uint col) const
{
    if (row >= m_size)
        throw std::out_of_range("row out of range");
    if (col >= m_size)
        throw std::out_of_range("col out of range");

    return is_open(row, col) &&
            check_full_uf->connected(0, row * m_size + col + 1);
}

// does the system percolate?
bool percolation::percolates() const
{
    return check_percolates_uf->connected(0, m_size * m_size + 1);
}

