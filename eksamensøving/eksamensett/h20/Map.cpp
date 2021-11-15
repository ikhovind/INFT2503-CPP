//
// Created by ingebrigt on 15.11.2021.
//

#include <vector>
#include "Map.h"

std::vector<int> operator|(std::vector<int> &in, Map map) {
    std::vector<int> new_vector;
    for (auto a : in) {
        new_vector.emplace_back(map.lambda(a));
    }
    return new_vector;
}
