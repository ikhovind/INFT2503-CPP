#include <iostream>
#include <functional>
#include <memory>
#include "Button.h"
#include "ToggleButton.h"
#include "LinkButton.h"

using namespace std;

int getAnswer() {
    return 42;
}

void getAnswer(int &a) {
    a = 42;
}

void getAnswer(int *& a) {
    a = new int(42);
}

void getAnswer(function<void(int)> a) {
    a(42);
}

int main() {
    cout << "oppgave 1: " << endl;
    cout << getAnswer() << endl;

    int answer1;
    getAnswer(answer1);
    cout << answer1 << endl;

    int *answer2;
    getAnswer(answer2);
    cout << *answer2 << endl;
    delete answer2;

    getAnswer([](int answer) {
        cout << answer << endl;
    });

    cout << "oppgave 2: " << endl;

    std::vector<std::unique_ptr<Button>> buttons;

    buttons.emplace_back(std::make_unique<ToggleButton>("Togglesomething", true, [] {
        cout << "Toggled something" << endl;
    }));

    buttons.emplace_back(std::make_unique<LinkButton>("Link to somewhere","https://ntnu.no", [] {
            cout << "Opened link" << endl;
        }));

    for (auto &button : buttons) {
        cout << *button << endl;
        button->activate();
        cout << *button << endl;
    }

    return 0;
}

