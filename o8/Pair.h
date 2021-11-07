//
// Created by ingebrigt on 26.09.2021.
//

#ifndef O8_PAIR_H
#define O8_PAIR_H

template <typename P1, typename P2>
class Pair {
public:
    P1 first;
    P2 second;
    Pair(P1 first, P2 second);
    bool operator<(Pair &other);
    bool operator>(Pair &other);
    Pair operator+(Pair &other);
};



#endif //O8_PAIR_H
