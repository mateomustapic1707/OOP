#include <iostream>

using namespace std;

int main() {
	int a{};
	int b{};
	cout << "Unesite prvi broj (a):"; cin >> a;
	cout << "Unesite drugi broj (b):"; cin >> b;
	int zbroj{ a + b };
	double aritmeticka_sredina{ (a + b) / 2 };
	bool je_manje{ a < b };
	cout << "Zbroj: " << zbroj << endl;
	cout << "Aritmeticka sredina: " << aritmeticka_sredina << endl;
	cout << "Usporedba: " << boolalpha << je_manje << endl;
	return 0;
}