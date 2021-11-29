#include <iostream>
#include <functional>
#include <memory>
#include <thread>
#include "Button.h"
#include "ToggleButton.h"
#include "LinkButton.h"
#include "Angle.h"

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

void parallell_transform(std::vector<int> &vec, int num_threads, std::function<int(int)> modifier) {
    static int counter = 0;
    std::vector<std::thread> threads;
    static std::mutex vec_lock;
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back([&vec, modifier]() {
            int local_counter = 0;
            while (counter < vec.size()) {
                vec_lock.lock();
                local_counter = counter++;
                vec_lock.unlock();
                vec[local_counter] = modifier(vec[local_counter]);
            }
        });
    }
    for (int i = 0; i < num_threads; ++i) {
        threads[i].join();

    }
}

template<typename T>
std::ostream& operator<<(std::ostream &out, std::vector<T> vec) {
    out << "{ ";

    for (int i = 0; i < vec.size(); ++i) {
        out << vec[i];
        if (i < vec.size() - 1) out << ", ";
    }
    out << " }";
    return out;
}
template<typename T>
std::vector<T> operator*(std::vector<T> a, std::vector<T> b) {
    for(int i = 0; i < a.size(); ++i) {
        a[i] *= b[i];
    }
    return a;
}

template<typename T>
std::vector<T> operator*(std::vector<T> a, int b) {
    for (int i = 0; i < a.size(); ++i) {
        a[i] = a[i] * b;
    }
    return a;
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

    std::cout << "oppgave 3:" << std::endl;

    Angle<int> angle1(30);
    cout << angle1 << endl;

    Angle<int> angle2(390);
    cout << angle2 << endl;

    Angle<double> angle3(3.14159265359 / 2);
    cout << angle3 << endl;

    Angle<double> angle4(3.14159265359 * 1.5);
    cout << angle4 << endl;

    std::cout << "oppgave 4" << std::endl;

    std::vector<int> opg4vec = {1, 2, 3, 4, 5, 6};

    parallell_transform(opg4vec, 4, [](int e) {
        return e * 2;
    });

    for (auto &e : opg4vec)
        std::cout << e << std::endl;

    std::cout << "oppgave 5" << std::endl;

    cout << std::vector<int>() << endl;
    cout << std::vector<float>({1.5, 2.5}) << endl;

    std::vector<int> vec = {1, 2, 3};
    cout << vec << endl;
    cout << vec * 3 << endl;
    cout << vec * vec << endl;

    return 0;
}

