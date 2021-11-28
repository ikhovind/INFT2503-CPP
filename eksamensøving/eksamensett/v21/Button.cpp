//
// Created by ingebrigt on 28/11/2021.
//

#include "Button.h"


void Button::activate() {


}


std::ostream &operator<<(std::ostream &out, Button &b) {
    out << b.print();
    return out;
}

std::string Button::print() {
    return "Button, label: " + name;
}
