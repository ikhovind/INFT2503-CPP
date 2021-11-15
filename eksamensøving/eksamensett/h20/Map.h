//
// Created by ingebrigt on 15.11.2021.
//

#ifndef H20_MAP_H
#define H20_MAP_H


#include <functional>

class Map {
private:
    std::function<int(int)> lambda;
public:
    Map(const std::function<int(int)> _lambda) : lambda(_lambda) {}
    friend std::vector<int> operator|(std::vector<int> &in, Map map);
};


#endif //H20_MAP_H
