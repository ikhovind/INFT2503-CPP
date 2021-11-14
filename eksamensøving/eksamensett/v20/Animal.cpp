//
// Created by ingebrigt on 14.11.2021.
//
#include "Animal.h"

Animal::Animal(std::string _name) {
    this->name = _name;
}

std::ostream &operator<<(std::ostream &out, Animal &cat) {
    out << cat.get_class() + " named " + cat.get_name();
    return out;
}
