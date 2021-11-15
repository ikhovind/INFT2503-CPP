//
// Created by ingebrigt on 15.11.2021.
//

#ifndef H20_MATVARE_H
#define H20_MATVARE_H
#include "Vare.h"

class MatVare : public Vare{
public:
    MatVare(std::string navn, size_t antall) : Vare(navn, antall, 0.25) {}
};


#endif //H20_MATVARE_H
