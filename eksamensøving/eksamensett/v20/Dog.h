//
// Created by ingebrigt on 14.11.2021.
//

#ifndef V20_DOG_H
#define V20_DOG_H


#include "Animal.h"

class Dog : public Animal{
public:
    Dog(std::string name) : Animal(name) {}
    std::string get_name() override;
    std::string get_class() override;
};

std::ostream &operator<<(std::ostream &out, Dog cat);

#endif //V20_DOG_H
