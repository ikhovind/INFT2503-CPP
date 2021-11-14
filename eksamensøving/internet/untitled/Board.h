//
// Created by ingebrigt on 08.11.2021.
//

#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H

#include <iosfwd>
#include <vector>

enum state {
    NONE,
    CIRCLE,
    CROSS
};
class Board {
private:
    std::vector<std::vector<state>> board;
public:
    Board();
    bool make_move(bool cross, int x, int y);
    state eval_winner();
    std::vector<std::vector<state>> get_board();
};

std::ostream &operator<<(std::ostream &out, Board b);


#endif //UNTITLED_BOARD_H
