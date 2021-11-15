//
// Created by ingebrigt on 15.11.2021.
//

#include <iostream>
#include "RGB.h"

template<typename T>
std::ostream &operator<<(std::ostream &out, const RGB<T> &in) {
    out << "(" + std::to_string(in.R) + ", " + std::to_string(in.G) + ", " + std::to_string(in.B) + ")";
    return out;
}

template<typename T>
RGB<T> RGB<T>::operator+(RGB<T> other) {
    if (std::is_same<T, double>::value) {
        double max_value = 1.0;
        auto r = std::min((double)this->R + other.R, max_value);
        auto g = std::min((double)this->G + other.G, max_value);
        auto b = std::min((double)this->B + other.B, max_value);

        return RGB<T>(r,g,b);
    }
    else if (std::is_same<T, int>::value) {
        int max_value = 255;
        auto r = std::min((int)(this->R + other.R), max_value);
        auto g = std::min((int)(this->G + other.G), max_value);
        auto b = std::min((int)(this->B + other.B), max_value);

        return RGB<T>(r,g,b);
    }
}

template<typename T>
RGB<T> RGB<T>::operator+(T value) {
    return RGB<T>(this->R + value, this->G + value, this->B + value);
}
