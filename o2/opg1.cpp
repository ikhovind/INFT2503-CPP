#include <iostream>
#include <cstring>

int main() {
    // opg 1
    // A)
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    std::cout << "i: " << i << " : " << &i << std::endl;
    std::cout << "j: " << j << " : " << &j << std::endl;
    std::cout << "p: " << *p << " : " << p << std::endl;
    std::cout << "q: " << *q << " : " << q << std::endl;

    // B)
    // i = 7
    *p = 7;
    // j = 5 + 4 = 9
    *q += 4;
    // j = i + 1 = 8
    *q = *p + 1;
    // *p = *q = j
    p = q;
    //8 8
    std::cout << *p << " " << *q << std::endl;
}
