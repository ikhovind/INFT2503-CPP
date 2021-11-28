//
// Created by ingebrigt on 28/11/2021.
//

#ifndef V21_BUTTON_H
#define V21_BUTTON_H


#include <functional>
#include <ostream>
#include <utility>
#include <memory>
#include <iostream>

class Button {
protected:
    std::string name;
    std::function<void()> onActivate;
    virtual std::string print();
public:
    Button(std::string _name, std::function<void()> _onActivate) : name(std::move(_name)), onActivate(std::move(_onActivate)) {};
    virtual void activate();
    friend std::ostream& operator<<(std::ostream &out, Button &b);
};


#endif //V21_BUTTON_H
