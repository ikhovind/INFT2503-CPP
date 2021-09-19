//
// Created by ingebrigt on 29.08.2021.
//
int main() {
    double number = 1.0;
    double *pointer = &number;
    double &reference = number;

    // måte 1
    number = 1.2;
    // måte 2
    *pointer = 1.4;
    // måte 3
    reference = 1.6;
}

