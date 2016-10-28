#include <utility>

#include "Percolation.h"

using namespace applications;

// create n-by-n grid, with all sites blocked
Percolation::Percolation(const uint n)
    : m_maze(n, std::vector<bool>(n, false)), m_size(n)
{
    // add 2 elements for virtual top and virtual bottom sites
    checkPercolatesUF = std::make_shared<WeightedUF>(n * n + 2);
    checkFullUF = std::make_shared<WeightedUF>(n * n + 1);
}

// open site (row, col) if it is not open already
void Percolation::open(uint row, uint col)
{
    if (row >= m_size)
        throw std::out_of_range("row out of range");
    if (col >= m_size)
        throw std::out_of_range("col out of range");

    m_maze[row][col] = true;

    if (row == 0)
    {
        checkPercolatesUF->connect(0, col + 1);
        checkFullUF->connect(0, col + 1);
    }

    if (row == m_size - 1)
        checkPercolatesUF->connect(m_size * m_size + 1, row * m_size + col + 1);

    if (row >= 1 && isOpen(row - 1, col))
    {
        checkPercolatesUF->connect(row * m_size + col + 1, (row - 1) * m_size + col + 1);
        checkFullUF->connect(row * m_size + col + 1, (row - 1) * m_size + col + 1);
    }

    if (row < (m_size - 1) && isOpen(row + 1, col))
    {
        checkPercolatesUF->connect(row * m_size + col + 1, (row + 1) * m_size + col + 1);

        if (row < m_size - 2)
            checkFullUF->connect(row * m_size + col + 1, (row + 1) * m_size + col + 1);
    }

    if (col >= 1 && isOpen(row, col - 1))
    {
        checkPercolatesUF->connect(row * m_size + col + 1, row * m_size + (col - 1) + 1);
        checkFullUF->connect(row * m_size + col + 1, row * m_size + (col - 1) + 1);
    }

    if (col < (m_size - 1) && isOpen(row, col + 1))
    {
        checkPercolatesUF->connect(row * m_size + col + 1, row * m_size + (col + 1) + 1);
        checkFullUF->connect(row * m_size + col + 1, row * m_size + (col + 1) + 1);
    }
}

// is site (row, col) open?
bool Percolation::isOpen(uint row, uint col) const
{
    if (row >= m_size)
        throw std::out_of_range("row out of range");
    if (col >= m_size)
        throw std::out_of_range("col out of range");

    return m_maze[row][col];
}

// is site (row, col) full?
bool Percolation::isFull(uint row, uint col) const
{
    if (row >= m_size)
        throw std::out_of_range("row out of range");
    if (col >= m_size)
        throw std::out_of_range("col out of range");

    return isOpen(row, col) &&
            checkFullUF->connected(0, row * m_size + col + 1);
}

// does the system percolate?
bool Percolation::percolates() const
{
    return checkPercolatesUF->connected(0, m_size * m_size + 1);
}

