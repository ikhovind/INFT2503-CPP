//
// Created by ingebrigt on 15.11.2021.
//

#ifndef H20_BUTIKK_H
#define H20_BUTIKK_H

#include <vector>
#include <memory>
#include "Vare.h"
#include "MatVare.h"


class Butikk {
public:
    std::vector<std::unique_ptr<Vare>> varer;
    Butikk() : varer() {};
};


#endif //H20_BUTIKK_H
