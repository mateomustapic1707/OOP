#include <iostream>
#include <string>
#include <cctype> // za toupper

using namespace std;

int main() {
    int godina_rodenja{};
    cout << "Unesite godinu rodenja: ";
    cin >> godina_rodenja;

    cin.ignore();

    string ime_i_prezime{};
    cout << "Unesite ime i prezime: ";
    getline(cin, ime_i_prezime);

    // 1. Ispis inicijala
    cout << "Inicijali: ";
    bool novo_slovo = true;
    for (char c : ime_i_prezime) {
        if (c != ' ' && novo_slovo) {
            cout << (char)toupper(c) << ".";
            novo_slovo = false;
        }
        else if (c == ' ') {
            novo_slovo = true;
        }
    }
    cout << endl;

    // 2. Broj znakova imena i prezimena bez razmaka
    int broj_znakova{ 0 };
    for (char c : ime_i_prezime) {
        if (c != ' ') {
            broj_znakova++;
        }
    }
    cout << "Broj znakova (bez razmaka): " << broj_znakova << endl;

    // 3. Koliko godina osoba navršava ove godine
    int trenutna_godina{ 2026 };
    int godina_navrsava{ trenutna_godina - godina_rodenja };
    cout << "Godina koje navrsava ove godine: " << godina_navrsava << endl;

    return 0;
}