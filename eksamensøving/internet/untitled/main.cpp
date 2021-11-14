#include <iostream>
#include "Board.h"

int main() {
    Board b;
    b.make_move(true, 0,0);
    b.make_move(true, 0,1);
    b.make_move(true, 0,2);
    std::cout << b << std::endl;
    return 0;
}
