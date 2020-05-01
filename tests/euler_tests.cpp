#include <catch2/catch.hpp>

#include "algorithms/graph_algorithms.h"
#include "data_structures/graph.h"
#include "euler/euler.h"
#include <iostream>
#include <memory>
#include <vector>

TEST_CASE("euler problems") {
    SECTION("power digit sum") {
        std::shared_ptr<interview::euler> euler = std::make_shared<interview::euler>();
        REQUIRE(1366 == euler->power_digit_sum(1000));
    }

    SECTION("power digit sum") {
        std::shared_ptr<interview::euler> euler = std::make_shared<interview::euler>();
        REQUIRE(21124 == euler->number_letter_counts(1000));
    }

    SECTION("maximum path sum") {
        std::shared_ptr<data_structures::graph> g = std::make_shared<data_structures::graph>();
        // std::vector<std::vector<int>> weights = {
        //     {3},
        //     {7, 4},
        //     {2, 4, 6},
        //     {8, 5, 9, 3}
        // };

        std::vector<std::vector<int>> weights = {
            {75},
            {95, 64},
            {17, 47, 82},
            {18, 35, 87, 10},
            {20,  4, 82, 47, 65},
            {19,  1, 23, 75,  3, 34},
            {88,  2, 77, 73,  7, 63, 67},
            {99, 65,  4, 28,  6, 16, 70, 92},
            {41, 41, 26, 56, 83, 40, 80, 70, 33},
            {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
            {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
            {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
            {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
            {63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
            { 4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23}
        };

        g->add_edge(0, 1, weights[0][0]);
        size_t u_start = 1;

        for (size_t i = 0; i < weights.size() - 1; ++i)
        {
            for (size_t j = 0; j < weights[i].size(); ++j)
            {
                size_t u = j + u_start;
                size_t v = u + weights[i].size();

                g->add_edge(u, v, weights[i + 1][j]);
                g->add_edge(u, v + 1, weights[i + 1][j + 1]);

                std::cout << u << " " << v << " " << weights[i + 1][j] << std::endl;
                std::cout << u << " " << v + 1 << " " << weights[i + 1][j + 1] << std::endl;
            }

            u_start += weights[i].size();
        }

        for (size_t j = 0; j < weights[weights.size() - 1].size(); ++j)
        {
            size_t u = j + u_start;
            size_t v = u_start + weights[weights.size() - 1].size();

            g->add_edge(u, v, 0);
        }

        std::vector<double> distances = algorithms::dijkstra_longest_path(0, g);
        REQUIRE(1074 == distances[distances.size() - 1]);
    }
}