#include <iostream>
#include <numeric> // za std::gcd

using namespace std;

struct Fraction {
    int numerator;
    int denominator;

    void reduce() {
        if (denominator == 0) return;
        int zajednicki = gcd(numerator, denominator);
        numerator /= zajednicki;
        denominator /= zajednicki;

        // Ako je nazivnik negativan, prebaci minus gore
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    double value() const {
        return static_cast<double>(numerator) / denominator;
    }

    void print() const {
        cout << numerator << "/" << denominator << endl;
    }
};

Fraction sum(const Fraction& a, const Fraction& b) {
    Fraction rez;
    rez.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    rez.denominator = a.denominator * b.denominator;
    rez.reduce();
    return rez;
}

int main() {
    Fraction f1{ 2, 4 };
    Fraction f2{ 1, 3 };

    cout << "Pocetni razlomak f1: ";
    f1.print();

    cout << "Nakon skracivanja f1: ";
    f1.reduce();
    f1.print();

    cout << "Decimalna vrijednost f1: " << f1.value() << endl;

    Fraction f3 = sum(f1, f2);
    cout << "Zbroj skracenih razlomaka (f1 + f2): ";
    f3.print();

    return 0;
}