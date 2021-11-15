//
// Created by ingebrigt on 15.11.2021.
//

#ifndef H20_VARE_H
#define H20_VARE_H


class Vare {
protected:
    Vare(std::string _navn, size_t _antall, double _mva) : navn(_navn), antall(_antall), mva(_mva) {};
public:
    const std::string navn;
    const size_t antall;
    const double mva;
    Vare(std::string _navn, size_t _antall) : navn(_navn), antall(_antall), mva(0.25) {};
};


#endif //H20_VARE_H
