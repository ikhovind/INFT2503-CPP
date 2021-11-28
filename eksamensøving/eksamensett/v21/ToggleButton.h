//
// Created by ingebrigt on 28/11/2021.
//

#ifndef V21_TOGGLEBUTTON_H
#define V21_TOGGLEBUTTON_H


#include "Button.h"

class ToggleButton : public Button{
private:
    bool toggled;
public:
    ToggleButton(std::string name, bool _toggled, std::function<void()> onActivate) :  Button(name, onActivate), toggled(_toggled) {};
    void activate() override;
    friend std::ostream &operator<<(std::ostream &out, ToggleButton tb);
    std::string print() override;
};


#endif //V21_TOGGLEBUTTON_H
