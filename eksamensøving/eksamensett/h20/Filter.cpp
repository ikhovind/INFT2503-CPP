//
// Created by ingebrigt on 15.11.2021.
//

#include "Filter.h"

std::vector<int> operator|(std::vector<int> &in, Filter map) {
    std::vector<int> out;
    for (auto a : in) {
        if (map.lambda(a)) {
            out.emplace_back(a);
        }
    }
    return out;
}
