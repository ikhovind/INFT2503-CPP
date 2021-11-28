//
// Created by ingebrigt on 28/11/2021.
//

#ifndef V21_LINKBUTTON_H
#define V21_LINKBUTTON_H

#include "Button.h"

class LinkButton : public Button {
private:
    std::string linkTo;
public:
    LinkButton(std::string label, std::string linkTo, std::function<void()> f) :  Button(label, f), linkTo(linkTo) {};
    void activate() override;
    std::string print() override;
};


#endif //V21_LINKBUTTON_H
