#include <iostream>
#include <iomanip>

template<typename Type>
bool are_equal(Type &t1, Type &t2) {
    std::cout << "using generic version of are_equal" << std::endl;
    return t1 == t2;
}

bool are_equal(double &t1, double &t2) {
    std::cout << "using double version of are_equal" << std::endl;
    return std::abs(t1 - t2) < 0.00001;
}

int main() {
    std::string s1 = "hei";;
    std::string s2 = "hei";;
    std::string s3 = "Hei";;
    double d1 = 1.0000000001;
    double d2 = 1.0000000001;
    double d3 = 1.001;

    std::cout << "are " << s1 << " and " << s2 << " equal? " << (are_equal(s1, s2) ? "true " : "false") << std::endl;
    std::cout << "are " << s1 << " and " << s3 << " equal? " << (are_equal(s1, s3) ? "true " : "false") << std::endl;
    std::cout << "are " << std::setprecision(12) << d1 << " and " << d2 << " equal? " << (are_equal(d1, d2) ? "true " : "false") << std::endl;
    std::cout << "are " << std::setprecision(12) << d1 << " and " << d3 << " equal? " << (are_equal(d1, d3) ? "true " : "false") << std::endl;
    return 0;
}
