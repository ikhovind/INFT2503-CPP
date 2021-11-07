#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::ostream &operator<<(std::ostream &out, const std::vector<int> &table) {
    for (auto &e : table)
        out << e << " ";
    return out;
}
int main() {
    std::vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    std::cout << "v1: " << v1 << std::endl;

    std::vector<int> v2 = {2, 3, 12, 14, 24};
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "oppgave a)" << std::endl;
    auto firstGreater = std::find_if(v1.begin(), v1.end(), [](int i){return i > 15;});
    std::cout << "First element greater than 15 in v1 is: " << *firstGreater << std::endl;

    std::cout << "oppgave b)" << std::endl;
    auto oneAndFive = std::equal(v1.begin(), v1.begin() + 5, v2.begin(), [](int i, int y){
        std::cout << i << " " << y << std::endl;
        return (abs(i - y) <= 2);});
    auto oneAndFour = std::equal(v1.begin(), v1.begin() + 4, v2.begin(), [](int i, int y){
        std::cout << i << " " << y << std::endl;
        return (abs(i - y) <= 2);});
    std::cout << "Elements up to V1[4] are within 2 of elements in V2: " << (oneAndFive ? "true" : "false") << std::endl;
    std::cout << "Elements up to V1[3] are within 2 of elements in V2: " << (oneAndFour ? "true" : "false") << std::endl;

    std::cout << "oppgave c)" << std::endl;
    std::replace_copy_if(v1.begin(), v1.end(), v1.begin(), [](int i){return i % 2;}, 100);
    std::cout << "v2: " << v1 << std::endl;
    return 0;
}
