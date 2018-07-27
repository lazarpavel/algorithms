#pragma once

#include <utility>

namespace algorithms
{
    // pseudocode source: https://en.wikipedia.org/wiki/Cycle_detection
    template <typename T>
    std::pair<uint, uint> detect_cycle_floyd(T (*f)(T& data), T& data)
    {
        // Main phase of algorithm: finding a repetition x_i = x_2i.
        // The fast moves twice as quickly as the slow and
        // the distance between them increases by 1 at each step.
        // Eventually they will both be inside the cycle and then,
        // at some point, the distance between them will be
        // divisible by the period λ.

        T slow = f(data);
        T fast = f(f(data));

        while (slow != fast)
        {
            slow = f(slow);
            fast = f(f(fast));
        }

        // At this point the slow position, V, which is also equal
        // to the distance between fast and slow, is divisible by
        // the period λ. So fast moving in circle one step at a time,
        // and slow (reset to initial data) moving towards the circle, will
        // intersect at the beginning of the circle. Because the
        // distance between them is constant at 2V, a multiple of λ,
        // they will agree as soon as the slow reaches index μ.

        // Find the position start_cycle of first repetition.
        uint start_cycle = 0;
        slow = data;

        while (slow != fast)
        {
            slow = f(slow);
            fast = f(fast);

            ++start_cycle;
        }

        // Find the length of the shortest cycle starting from x_μ
        // The fast moves one step at a time while slow is still.
        // end_cycle is incremented until λ is found.

        uint end_cycle = 1;
        fast = f(slow);

        while (fast != slow)
        {
            fast = f(fast);
            ++end_cycle;
        }

        return std::make_pair<uint, uint>(start_cycle, end_cycle);
    }

    // pseudocode source: https://en.wikipedia.org/wiki/Cycle_detection
    template <typename T>
    std::pair<uint, uint> detect_cycle_brent(T (*f)(T& data), T& data)
    {
        uint power = 1;
        uint end_cycle = 1;

        T slow = data;
        T fast = f(data);

        while (fast != slow)
        {
            if (power == end_cycle)
            {
                slow = fast;
                power = power << 1;
                end_cycle = 0;
            }

            fast = f(fast);
            ++end_cycle;
        }

        uint start_cycle = 0;
        slow = data;
        fast = data;

        for (uint it = 0; it < end_cycle; ++it)
            fast = f(fast);

        while (fast != slow)
        {
            slow = f(slow);
            fast = f(fast);

            ++start_cycle;
        }

        return std::make_pair<uint, uint>(start_cycle, end_cycle);
    }
}
