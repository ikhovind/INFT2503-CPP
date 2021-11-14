//
// Created by ingebrigt on 08.11.2021.
//

#include <ostream>
#include "Board.h"

Board::Board() {
    for (int i = 0; i < 3; ++i) {
        board.emplace_back(std::vector<state>());
        for (int j = 0; j < 3; ++j) {
            board[i].emplace_back(NONE);
        }
    }
}
state Board::eval_winner() {
    state winner = NONE;
    // horisontalt
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != NONE && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    // vertikalt
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] != NONE && board[1][i] == board[1][i] && board[i][1] == board[2][i]) {
            return board[0][i];
        }
    }
    // på skrå
    if (board[0][0] != NONE && board[0][0] == board[1][1] && board[2][2]) {
        return board[0][0];
    }
    if (board[2][0] != NONE && board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
        return board[0][0];
    }
    return NONE;
}

bool Board::make_move(bool cross, int x, int y) {
    if (board[y][x] != NONE) return false;
    board[y][x] = (cross ? CROSS : CIRCLE);
    return true;
}

std::vector<std::vector<state>> Board::get_board() {
   return this->board;
}

std::string enum_to_string(state s) {
    if (s == NONE) return " ";
    if (s == CROSS) return "X";
    return "O";
}
std::ostream &operator<<(std::ostream &out, Board b) {
    std::string val;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            val += enum_to_string(b.get_board()[i][j]);
        }
        val += "\n";
    }
    out << val;
    return out;
}
