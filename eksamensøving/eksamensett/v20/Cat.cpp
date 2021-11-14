//
// Created by ingebrigt on 14.11.2021.
//

#include "Cat.h"

std::string Cat::get_name() {
    return this->name;
}

std::string Cat::get_class() {
    return "Cat";
}

std::ostream &operator<<(std::ostream &out, Cat cat) {
    out << "Cat named " + cat.get_name();
    return out;
}
