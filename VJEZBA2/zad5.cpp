#include <iostream>

using namespace std;

inline double add(double a, double b) { return a + b; }
inline double subtract(double a, double b) { return a - b; }
inline double multiply(double a, double b) { return a * b; }
inline double divide(double a, double b) { return a / b; }

int main() {
    // Niz pokazivača na funkcije
    double (*operacije[])(double, double) = { add, subtract, multiply, divide };

    double a, b;
    int op;

    cout << "Unesi dva broja: ";
    cin >> a >> b;
    cout << "Odaberi operaciju (0: +, 1: -, 2: *, 3: /): ";
    cin >> op;

    if (op < 0 || op > 3) {
        cout << "Nevaljala operacija!" << endl;
    }
    else if (op == 3 && b == 0) {
        cout << "Greska: Dijeljenje s nulom nije dozvoljeno!" << endl;
    }
    else {
        cout << "Rezultat: " << operacije[op](a, b) << endl;
    }

    return 0;
}