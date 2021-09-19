#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<double> vec {1.0, 1.1, 1.2, 1.3, 1.4};
    std::cout << vec.front() << std::endl;
    std::cout << vec.back() << std::endl;

    vec.emplace(vec.begin() + 1, 1.05);
    std::cout << vec.front() << std::endl;

    auto res = std::find(vec.begin(), vec.end(), 1.3);

    if (res != vec.end()) {
        std::cout << "found element: " << *res <<
        ", at index: "<< res - vec.begin() - 1 << std::endl;

    }
    else {
        std::cout << "no element found" << std::endl;
    }
    return 0;
}
