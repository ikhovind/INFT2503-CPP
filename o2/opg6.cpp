#include <iostream>

int find_sum(const int *table, int length);

int main() {
    int table[20];
    for (int i = 0; i < 20; ++i) {
        table[i] = i;
    }

    int tenFirst = find_sum(table, 10);
    std::cout << "sum of ten first: " << tenFirst << std::endl;
    int fiveNext = find_sum(&table[10], 5);
    std::cout << "sum of five next: " << fiveNext << std::endl;
    int fiveLast = find_sum(&table[15], 5);
    std::cout << "sum of five last: " << fiveLast << std::endl;
}

int find_sum(const int *table, int length) {
    int sum = 0;
    int counter = 0;
    while (table + counter < &table[length]) {
        sum += *(table + counter);
        counter++;
    }
    return sum;
}