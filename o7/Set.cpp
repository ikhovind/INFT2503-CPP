//
// Created by ingebrigt on 24.09.2021.
//

#include <algorithm>
#include <ostream>
#include <iostream>
#include "Set.h"

Set::Set() = default;

Set Set::operator+(int other) {
    Set newThis = *this;
    if (std::find(newThis.nums.begin(), newThis.nums.end(), other) == newThis.nums.end()) {
        newThis.nums.emplace_back(other);
    }
    return newThis;
}

Set Set::operator+(Set &other) {
    for (int otherNum : other.nums) {
        if (std::find(this->nums.begin(), this->nums.end(), otherNum) == this->nums.end()) {
            this->nums.emplace_back(otherNum);
        }
    }
    return other;
}

Set Set::operator+=(int other) {
    *this = *this + other;
    return *this;
}

Set Set::operator+=(Set &other) {
    return *this + other;
}

Set operator+(int integer, Set &set) {
    return set + integer;
}

std::ostream &operator<<(std::ostream &out, Set &nums) {
    std::string numString = "<";
    for (int n : nums.nums) {
        numString.append(std::to_string(n) + ", ");
    }
    if (numString.length() > 1) {
        numString = numString.substr(0, numString.length() - 2);
    }
    numString.append(">");
    out << numString;
    return out;
}

