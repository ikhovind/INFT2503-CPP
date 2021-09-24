//
// Created by ingebrigt on 24.09.2021.
//

#ifndef O7_SET_H
#define O7_SET_H
#pragma once

#include <vector>
#include <ostream>
#include "fraction.hpp"

class Set {
public:
    std::vector<int> nums;

    Set();
    Set operator+(Set &other);
    Set operator+(int other);
    Set operator+=(int other);
    Set operator+=(Set &other);
};

Set operator+(int integer, Set &set);
std::ostream &operator<<(std::ostream &out, Set &nums);

#endif //O7_SET_H
