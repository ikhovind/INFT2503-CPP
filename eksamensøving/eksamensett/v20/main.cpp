#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Currency.cpp"

std::string escape(const std::string &b) {
    std::string s = b;
    for (int i = 0; i < s.length(); i++) {
        if (toascii(s.at(i)) ==  '<' || toascii(s.at(i)) ==  '&' ||  toascii(s.at(i)) ==  '>') {
            std::cout << s.at(i) << std::endl;
            switch (s.at(i)) {
                case '<':
                    s.replace(s.begin() + i, s.begin() + i + 1, "&lt;");
                    break;
                case '>':
                    s.replace(s.begin() + i, s.begin() + i + 1, "&gt;");
                    break;
                case '&':
                    s.replace(s.begin() + i, s.begin() + i + 1, "&amp;");
                    break;
            }
        }
    }
    return s;
}
void escape(std::string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (toascii(s.at(i)) ==  '<' || toascii(s.at(i)) ==  '&' ||  toascii(s.at(i)) ==  '>') {
            std::cout << s.at(i) << std::endl;
            switch (s.at(i)) {
                case '<':
                    s.replace(s.begin() + i, s.begin() + i + 1, "&lt;");
                    break;
                case '>':
                    s.replace(s.begin() + i, s.begin() + i + 1, "&gt;");
                    break;
                case '&':
                    s.replace(s.begin() + i, s.begin() + i + 1, "&amp;");
                    break;
            }
        }
    }
}

int main() {
    std::cout << escape("Escape these symbols: <<&>>") << std::endl;
    std::string text("Escape these symbols as well: >>&<<");
    escape(text);
    std::cout << text << std::endl;

    std::cout << "oppgave 2" << std::endl;

    std::vector<std::unique_ptr<Animal>> animals;
    animals.emplace_back(new Cat("Oreo"));
    animals.emplace_back(new Dog("Buddy"));
    animals.emplace_back(new Dog("Charlie"));
   // animals.emplace_back(new Animal()); // Should cause compilation error
   // animals.emplace_back(new Animal("Max")); // Should cause compilation
    // error
    for (auto &animal : animals)
        std::cout << *animal << std::endl;

    std::cout << "oppgave 3" << std::endl;
    std::cout << Currency<NorwegianKrone>(1) << std::endl;
    std::cout << Currency<Euro>(1) << std::endl;
    std::cout << (Currency<NorwegianKrone>(10) +
             Currency<Euro>(10) +
             Currency<NorwegianKrone>(10)) << std::endl;

    std::cout << "oppgave 5" << std::endl;
    std::vector<int> vec = {2, 5, 2, 5, 1, 5, 1};
    std::cout << "a)" << std::endl;
    std::swap_ranges(vec.begin(), vec.begin() + 3, vec.begin() + 4);
    for (auto &e: vec) {
        std::cout << e << std::endl;
    }

    vec = {2, 5, 2, 5, 1, 5, 1};
    std::cout << "b)" << std::endl;
    std::rotate(vec.begin(), vec.begin() + 1, vec.end());
    for (auto &e: vec) {
        std::cout << e << std::endl;
    }
    std::cout << "c)" << std::endl;
    vec = {2, 5, 2, 5, 1, 5, 1};
    std::transform(vec.begin(), vec.end(), vec.begin(), [](int i){return i << 1;} );
    for (auto &e: vec) {
        std::cout << e << std::endl;
    }


    return 0;
}
