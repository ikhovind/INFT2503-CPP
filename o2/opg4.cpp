//
// Created by ingebrigt on 29.08.2021.
//
int main() {
    int a = 5;
    //referanser må initieres
    int &b = a;
    int *c;
    c = &b;
    // a er en variabel og ikke en peker, kan ikke bruke * for å dereferere da
    // b er en referanse og ikke en peker, trenger da ikke å dereferere for å hente ut verdien
    a = b + *c;
    // &b er minnelokasjonen til referansen b, denne kan ikke settes
    b = 2;
}

