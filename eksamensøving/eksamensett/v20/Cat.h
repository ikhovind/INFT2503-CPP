//
// Created by ingebrigt on 14.11.2021.
//

#include <string>
#include "Animal.h"
#ifndef V20_CAT_H
#define V20_CAT_H


class Cat :public Animal{
public:
    Cat(std::string name) : Animal(name) {};
    std::string get_name() override;
    std::string get_class() override;
};

std::ostream &operator<<(std::ostream &out, Cat cat);

#endif //V20_CAT_H
