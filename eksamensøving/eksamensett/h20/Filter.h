//
// Created by ingebrigt on 15.11.2021.
//

#ifndef H20_FILTER_H
#define H20_FILTER_H


#include <functional>
#include <vector>

class Filter {
private:
    std::function<bool(int)> lambda;
public:
    Filter(const std::function<bool(int)> _lambda) : lambda(_lambda) {}
    friend std::vector<int> operator|(std::vector<int> &in, Filter map);
};


#endif //H20_FILTER_H
