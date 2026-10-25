#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Funkcija koja dijeli rečenicu na riječi koristeći find i substr (uz podršku za više razmaka)
vector<string> split_words(const string& text) {
    vector<string> rijeci;
    size_t pocetak = 0;
    size_t duljina = text.length();

    while (pocetak < duljina) {
        // Preskoči vodeće razmake
        while (pocetak < duljina && text[pocetak] == ' ') {
            ++pocetak;
        }
        if (pocetak >= duljina) {
            break;
        }

        // Pronađi kraj trenutne riječi (sljedeći razmak)
        size_t kraj = text.find(' ', pocetak);
        if (kraj == string::npos) {
            kraj = duljina;
        }

        // Izvuci riječ i spremi je u vektor
        rijeci.push_back(text.substr(pocetak, kraj - pocetak));
        pocetak = kraj;
    }

    return rijeci;
}

int main() {
    string recenica;
    cout << "Unesite recenicu: ";
    getline(cin, recenica);

    // Poziv funkcije
    vector<string> rijeci = split_words(recenica);

    if (rijeci.empty()) {
        cout << "Niste unijeli nijednu rijec.\n";
        return 0;
    }

    // 1. Broj riječi i najdulja riječ
    cout << "broj rijeci: " << rijeci.size() << "\n";

    string najdulja = rijeci[0];
    for (const string& r : rijeci) {
        if (r.length() > najdulja.length()) {
            najdulja = r;
        }
    }
    cout << "najdulja: " << najdulja << "\n";

    // 2. Riječi obrnutim redoslijedom, spojene znakom - u jedan string (+=)
    string obrnuto_spojeno = "";
    for (int i = rijeci.size() - 1; i >= 0; --i) {
        obrnuto_spojeno += rijeci[i];
        if (i > 0) {
            obrnuto_spojeno += "-";
        }
    }
    cout << obrnuto_spojeno << "\n";

    // 3. Riječ koja je prva po abecedi (operator <)
    string prva_abeceda = rijeci[0];
    for (const string& r : rijeci) {
        if (r < prva_abeceda) {
            prva_abeceda = r;
        }
    }
    cout << "prva po abecedi: " << prva_abeceda << "\n";

    return 0;
}