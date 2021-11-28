//
// Created by ingebrigt on 28/11/2021.
//

#include "ToggleButton.h"

void ToggleButton::activate() {
    toggled = !toggled;
    onActivate();
}

std::ostream &operator<<(std::ostream &out, ToggleButton tb) {
    return out;
}

std::string ToggleButton::print() {
    return "ToggleButton, label: " + name + ", value: " + (toggled ? "toggled" : "not toggled");
}
