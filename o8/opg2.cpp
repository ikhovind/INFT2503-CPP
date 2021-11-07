#include <iostream>
#include "Pair.cpp"

int main() {
    Pair<double, int> p1(3.5, 14);
    Pair<double, int> p2(2.1, 7);
    std::cout << "p1: " << p1.first << ", " << p1.second << std::endl;
    std::cout << "p2: " << p2.first << ", " << p2.second << std::endl;

    if (p1 > p2)
        std::cout << "p1 er størst" << std::endl;
    else
        std::cout << "p2 er størst" << std::endl;

    auto sum = p1 + p2;
    std::cout << "Sum: " << sum.first << ", " << sum.second << std::endl;

    /*
     * En operator for å legge sammen to par
     her så forutsetter jeg at += finnes, da jeg kun har implementert + operatoren
     * En operator for å finne ut om et par er større enn et annet par.
     * Her skal du sammenligne summen av elementene i hvert enkelt par, se eksemplet nedenfor
     Her så har jeg implementert både < og >, men for full funksjonalitet så hadde jeg trengt >= og <=, så
     forutsetter derfor at de finnes
     */
}

/* Utskrift:
p1: 3.5, 14
p2: 2.1, 7
p1 er størst
Sum: 5.6, 21
*/
