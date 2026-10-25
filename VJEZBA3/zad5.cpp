#include <iostream>
#include <string>

using namespace std;

// Umeće točku ispred svake skupine od tri znamenke, gledano s desna (insert)
string with_separators(string digits) {
    // Provjera je li broj negativan (preskačemo minus znak kod umetanja)
    bool negativan = false;
    if (!digits.empty() && digits[0] == '-') {
        negativan = true;
    }

    int pocetni_indeks = negativan ? 1 : 0;
    int duljina = digits.length();

    // Krećemo od kraja prema početku, računajući znamenke
    int brojac = 0;
    for (int i = duljina - 1; i >= pocetni_indeks; --i) {
        brojac++;
        // Svaka 3. znamenka, a da nismo došli do samog početka broja
        if (brojac % 3 == 0 && i != pocetni_indeks) {
            digits.insert(i, ".");
        }
    }

    return digits;
}

// Uklanja sve točke (find, erase)
string without_separators(string text) {
    size_t pozicija = text.find('.');
    while (pozicija != string::npos) {
        text.erase(pozicija, 1);
        pozicija = text.find('.', pozicija); // Nastavi tražiti dalje
    }
    return text;
}

int main() {
    string broj_str = "123456789";
    cout << "Original: " << broj_str << "\n";

    string sa_tockama = with_separators(broj_str);
    cout << "Sa separatorima: " << sa_tockama << "\n";

    cout << "Bez separatora: " << without_separators(sa_tockama) << "\n";

    return 0;
}