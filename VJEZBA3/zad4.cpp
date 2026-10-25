#include <iostream>
#include <string>

using namespace std;

bool split_email(const string& email, string& user, string& domain) {
    // Provjera: nema znaka @ ili ih ima više (find, rfind)
    size_t prvi_at = email.find('@');
    size_t zadnji_at = email.rfind('@');

    if (prvi_at == string::npos || prvi_at != zadnji_at) {
        return false;
    }

    // Provjera: @ je na početku ili na kraju
    if (prvi_at == 0 || prvi_at == email.length() - 1) {
        return false;
    }

    // Dijeljenje na korisničko ime i domenu
    user = email.substr(0, prvi_at);
    domain = email.substr(prvi_at + 1);

    // Provjera: u domeni nema točke
    if (domain.find('.') == string::npos) {
        return false;
    }

    return true;
}

int main() {
    string email;
    cout << "Unesite e-mail adresu: ";
    getline(cin, email);

    string user, domain;
    if (split_email(email, user, domain)) {
        cout << "-> korisnik: " << user << ", domena: " << domain << "\n";
    }
    else {
        cout << "-> neispravna adresa\n";
    }

    return 0;
}