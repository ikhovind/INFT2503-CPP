//
// Created by ingebrigt on 11/29/21.
//

#ifndef V21_ANGLE_H
#define V21_ANGLE_H

#include <ostream>

template <typename T>
class Angle {
private:
    T t1;
public:
    explicit Angle(T _t1) : t1(_t1) {};

    template<class A>
    friend std::ostream& operator << (std::ostream& out, const Angle<A>& e);
    friend std::ostream& operator <<(std::ostream& out, const Angle<int> &e);
    friend std::ostream& operator <<(std::ostream& out, const Angle<double> &e);
};



#endif //V21_ANGLE_H
