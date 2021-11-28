//
// Created by ingebrigt on 28/11/2021.
//

#include "LinkButton.h"

void LinkButton::activate() {
    onActivate();
}

std::string LinkButton::print() {
    return "LinkButton, label: " + name + ", link: " + linkTo;
}