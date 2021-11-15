#include <iostream>
#include "Butikk.h"
#include "ThreadSafeGrowingList.h"
#include <thread>
#include <chrono>
#include "RGB.cpp"
#include "Map.h"
#include "Filter.h"

void spaces_to_underscore2(std::string &original) {
    while (original.find(' ') != std::string::npos) {
        auto pos = original.find(' ');
        original.replace(pos, 1, 1, '_');
    }
}
std::string spaces_to_underscore1(const std::string &original) {
    std::string new_string = original;
    while (new_string.find(' ') != std::string::npos) {
        auto pos = new_string.find(' ');
        new_string.replace(pos, 1, 1, '_');
    }
    return new_string;
}
std::string spaces_to_underscore_or_character(const std::string &original, char *character) {
    std::string new_string = original;
    while (new_string.find(' ') != std::string::npos) {
        auto pos = new_string.find(' ');
        new_string.replace(pos, 1, 1, (character == nullptr ? '_' : *character));
    }
    return new_string;
}

std::string spaces_to_underscore_or_character(const std::string &original) {
    return spaces_to_underscore1(original);
}

std::ostream &operator<<(std::ostream &out, std::vector<int> in) {
    for (auto a : in) {
        out << a << ", ";
    }
    return out;
}
int main() {
    std::cout << "oppgave 1" << std::endl;
    std::cout << spaces_to_underscore1("this is a string") << std::endl;
    std::string str("this is a string");
    spaces_to_underscore2(str);
    std::cout << str << std::endl;
    char chr('+');
    std::cout << spaces_to_underscore_or_character("this is a string", &chr) << std::endl;
    std::cout << spaces_to_underscore_or_character("this is a string", nullptr) << std::endl;
    std::cout << spaces_to_underscore_or_character("this is a string") << std::endl;

    std::cout << "oppgave 2" << std::endl;
    Butikk butikk;
    butikk.varer.emplace_back(new MatVare("NTNU-nistepakken", 5));
    butikk.varer.emplace_back(new Vare("NTNU-koppen", 10));
    for (auto &v : butikk.varer) {
        std::cout << v->navn << ", "
        << v->antall << ", "
        << v->mva
        << std::endl;
    }
    std::cout << "oppgave 3" << std::endl;

    ThreadSafeGrowingList list;
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back([&list, i] {
            list.add(i);
        });
    }
    list.for_each([](int value) {
        std::cout << value << std::endl;
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(200ms);
    });
    for (auto &thread : threads)
        thread.join();

    std::cout << "Oppgave 4" << std::endl;

    {
        RGB<double> rgb(0.5);
        std::cout << rgb << std::endl;
        std::cout << rgb + 0.3 << std::endl;
        std::cout << rgb + 0.3 + RGB<double>(0.5, 0.1, 0.1) << std::endl;
    }
    {
        RGB<int> rgb(130);
        std::cout << rgb << std::endl;
        std::cout << rgb + 60 << std::endl;
        std::cout << rgb + 60 + RGB<int>(100, 30, 30) << std::endl;
    }

    std::cout << "oppgave 5" << std::endl;
    std::cout << "map" << std::endl;
    std::vector<int> vec = {1, 2, 3};
    std::vector<int> vecMultipliedBy2 = vec | Map([](int e) { return e * 2; });
    std::cout << vecMultipliedBy2 << std::endl;

    std::cout << "filter" << std::endl;
    std::vector<int> vecFiltered = vec | Filter([](int e) { return e % 2 == 1;
    });
    std::cout << vecFiltered << std::endl;
    return 0;
}
