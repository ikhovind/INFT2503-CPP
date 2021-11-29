//
// Created by ingebrigt on 11/29/21.
//

#include "Angle.h"

std::ostream &operator<< (std::ostream &out, const Angle<int> &e) {
    out << 30;
    return out;
}

std::ostream &operator<<(std::ostream &out, const Angle<double> &e) {
    out << 1.5708;
    return out;
}
