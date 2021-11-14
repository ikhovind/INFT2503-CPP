//
// Created by ingebrigt on 14.11.2021.
//

#ifndef V20_ANIMAL_H
#define V20_ANIMAL_H


#include <string>

class Animal {
protected:
    std::string name;
public:
    Animal(std::string _name);
    virtual std::string get_name() = 0;
    virtual std::string get_class() = 0;
};

std::ostream &operator<<(std::ostream &out, Animal &animal);


#endif //V20_ANIMAL_H
