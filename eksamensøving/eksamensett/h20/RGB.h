//
// Created by ingebrigt on 15.11.2021.
//

#ifndef H20_RGB_H
#define H20_RGB_H
#include <type_traits>
#include <ostream>


template<typename T>
class RGB {
    static_assert(std::is_arithmetic<T>::value, "T must be numeric");
public:
    T R;
    T G;
    T B;
    RGB(T _value) : R(_value), G(_value), B(_value) {}
    RGB(T _R, T _G, T _B) : R(_R), G(_G), B(_B) {}
    RGB<T> operator+(RGB<T> other);
    RGB<T> operator+(T value);
};

template<typename T>
std::ostream &operator<<(std::ostream &out, const RGB<T> &in);



#endif //H20_RGB_H
