//
// Created by ingebrigt on 26.09.2021.
//

#include "Pair.h"


template<typename P1, typename P2>
bool Pair<P1, P2>::operator<(Pair &other) {
    return (other.first + other.second > this->first + this->second);
}

template<typename P1, typename P2>
Pair<P1, P2> Pair<P1, P2>::operator+(Pair &other) {
    return Pair{this->first + other.first, this->second + other.second};
}

template<typename P1, typename P2>
bool Pair<P1, P2>::operator>(Pair &other) {
    return (other.first + other.second < this->first + this->second);
}

template<typename P1, typename P2>
Pair<P1, P2>::Pair(P1 first, P2 second) {
    this->first = first;
    this->second = second;
}

