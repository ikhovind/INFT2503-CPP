//
// Created by ingebrigt on 24.09.2021.
//
#include <iostream>
#include "Set.h"
int main() {
    Set set;
    Set set2;
    set2 = set2 + 5;
    std::cout << set << std::endl;
    set = set + 1;
    std::cout << set << std::endl;
    set = 2 + set;
    std::cout << set << std::endl;
    set += 3;
    std::cout << set << std::endl;
    set += set2;
    std::cout << set << std::endl;
    // trenger ikke å overloade =
    set = set2;
    std::cout << set << std::endl;
    return 0;
}

