#include <iostream>
#include "fraction.hpp"

int main() {
    Fraction fraction1{1,2};
    // 0.5 - 5 = -4.5 = -9/2
    fraction1 = fraction1 - 5;
    std::cout << fraction1.numerator << " / " << fraction1.denominator << std::endl;
    // 5 - -4.5 = 9.5 = 19 / 2
    fraction1 = 5 - fraction1;
    std::cout << fraction1.numerator << " / " << fraction1.denominator << std::endl;
    return 0;
}
