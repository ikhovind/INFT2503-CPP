#include <iostream>
#include "oppgaveoversikt.h"
#include "student.h"

int main() {
    oppgaveoversikt a;
    bool cont = true;
    std::string input;
    std::cout << ("ta et valg:\n"
                 "1: print ut nåværende studenter\n"
                 "2: øk antall poeng for en gitt student\n"
                 "3: registrer en ny student\n"
                 "9: avslutt programmet");
    while (cont) {
        std::cin >> input;
        switch (std::stoi(input)) {
            case 1:
                std::cout << a << std::endl;
                break;
            case 2:
            {
                std::string navn;
                std::string poeng;
                std::cout << "navn: " << std::endl;
                std::cin >> navn;
                std::cout << "poeng: " << std::endl;
                std::cin >> poeng;
                a.increase_points_for_student(navn, std::stoi(poeng));
                break;
            }
            case 3:
            {
                std::string navn;
                std::cout << "navn: " << std::endl;
                std::cin >> navn;
                student s(navn);
                if(a.register_new_student(s)) {
                    std::cout << "suksess" << std::endl;
                }
                else {
                    std::cout << "studenten finnes allerede" << std::endl;
                }
                break;
            }
            case 9:
                cont = false;
                break;
            default:
                std::cout << "Du skrev noe feil" << std::endl;
                std::cout << ("ta et valg:\n"
                              "1: print ut nåværende studenter\n"
                              "2: øk antall poeng for en gitt student\n"
                              "3: registrer en ny student\n"
                              "9: avslutt programmet\n");
                break;
        }
    }
    return 0;
}
