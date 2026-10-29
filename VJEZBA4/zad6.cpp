#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

vector<string> split_words(const string& text) {
    vector<string> rijeci;
    size_t pocetak = 0;
    size_t duljina = text.length();

    while (pocetak < duljina) {
        while (pocetak < duljina && text[pocetak] == ' ') ++pocetak;
        if (pocetak >= duljina) break;

        size_t kraj = text.find(' ', pocetak);
        if (kraj == string::npos) kraj = duljina;

        rijeci.push_back(text.substr(pocetak, kraj - pocetak));
        pocetak = kraj;
    }
    return rijeci;
}

int main() {
    vector<string> rjecnik = {
        "programski", "jezik", "c++", "je", "brz", "i",
        "mocan", "ali", "nije", "jednostavan", "za", "pocetnike"
    };

    sort(rjecnik.begin(), rjecnik.end());

    string recenica;
    cout << "Recenica: ";
    getline(cin, recenica);


    vector<string> rijeci_recenice = split_words(recenica);

    vector<string> nepoznate;
    for (string r : rijeci_recenice) {

        r.erase(
            remove_if(r.begin(), r.end(), [](unsigned char c) {
                return c == ',' || c == '.';
                }),
            r.end()
        );


        for (char& c : r) {
            c = tolower(c);
        }


        if (!r.empty() && !binary_search(rjecnik.begin(), rjecnik.end(), r)) {
            nepoznate.push_back(r);
        }
    }

    cout << "nepoznatih rijeci: " << nepoznate.size();
    for (const auto& nr : nepoznate) {
        cout << " " << nr;
    }
    cout << "\n";

    return 0;
}