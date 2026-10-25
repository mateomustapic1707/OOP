#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Unesite broj dana: ";
    cin >> n;

    // Vektor temperatura stvorite konstruktorom s n elemenata i popunite ga preko indeksa
    vector<double> temperature(n);
    cout << "Unesite temperature za " << n << " dana:\n";
    for (int i = 0; i < n; ++i) {
        cin >> temperature[i];
    }

    // Napravite novi vektor promjena temperature između susjednih dana
    // Za novi vektor unaprijed rezervirajte mjesto (capacity)
    vector<double> promjene;
    if (n > 1) {
        promjene.reserve(n - 1);
        // Vektor temperatura prođite iteratorima
        auto it = temperature.begin();
        auto sljedeci = it + 1;
        while (sljedeci != temperature.end()) {
            promjene.push_back(*sljedeci - *it);
            ++it;
            ++sljedeci;
        }
    }

    // Ispis promjena (za primjer iz zadatka)
    cout << "Promjene: ";
    for (double p : promjene) {
        cout << p << " ";
    }
    cout << "\n";

    // Za izvještaj je potrebno točno 7 dana.
    // Jednim pozivom resize skratite vektor na 7 dana ako je uneseno više, 
    // odnosno dopunite ga do 7 dana temperaturom zadnjeg izmjerenog dana ako je uneseno manje.
    double zadnja_temp = temperature.empty() ? 0.0 : temperature.back();
    temperature.resize(7, zadnja_temp);

    cout << "Izvjestaj (tocno 7 dana): ";
    for (double t : temperature) {
        cout << t << " ";
    }
    cout << "\n";

    return 0;
}