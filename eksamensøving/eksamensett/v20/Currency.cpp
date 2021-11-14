//
// Created by ingebrigt on 14.11.2021.
//

#include "iostream"

#include <iostream>

enum Currencies{
    Euro,
    NorwegianKrone
};
template <Currencies T>
class Currency {
private:
    int amount;
public:
    explicit Currency(int _amount) : amount(_amount) {} ;
    constexpr Currencies get_currency() const {
        return T;
    }
    int get_amount() const {
        return amount;
    }
    friend std::ostream &operator<<(std::ostream &out, const Currency<T> &currency) {
        if (currency.get_currency() == NorwegianKrone) {

            out << "€" + std::to_string(double(currency.get_amount()) / 10);
            return out;
        }
        out << "€" + std::to_string((currency.get_amount()));
        return out;
    }
};

template<Currencies T, Currencies T2>
Currency<T> operator+(Currency<T> t, const Currency<T2> &other) {
    if (t.get_currency() == other.get_currency()) {
        return Currency<T>(t.get_amount() + other.get_amount());
    }
    if (t.get_currency() == Euro) {
        return Currency<T>(t.get_amount() + other.get_amount() / 10);
    }
    return Currency<T>(t.get_amount() + other.get_amount() * 10);
}

