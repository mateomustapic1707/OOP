#include <iostream>
#include <array>
#include <numeric>
#include <algorithm>

using namespace std;

constexpr int DAYS = 7;

// Funkcija koja vraća ukupan broj sati u tjednu
double total(const array<double, DAYS>& sati) {
    double suma = 0;
    for (double s : sati) {
        suma += s;
    }
    return suma;
}

// Funkcija koja vraća redni broj dana (od 1) s najviše sati učenja
int best_day(const array<double, DAYS>& sati) {
    int index_najvise = 0;
    for (int i = 1; i < DAYS; ++i) {
        if (sati[i] > sati[index_najvise]) {
            index_najvise = i;
        }
    }
    return index_najvise + 1; // Redni broj dana od 1 do 7
}

int main() {
    // Za prvi tjedan korisnik unosi sate za svaki dan
    array<double, DAYS> tjedan1;
    cout << "Unesite sate učenja za 1. tjedan (7 dana):\n";
    for (int i = 0; i < DAYS; ++i) {
        cin >> tjedan1[i];
    }

    cout << "Ukupan broj sati (1. tjedan): " << total(tjedan1) << "\n";
    cout << "Dan s najviše sati (1. tjedan): " << best_day(tjedan1) << "\n";

    // Drugi tjedan popunite s fill(1.5)
    array<double, DAYS> tjedan2;
    tjedan2.fill(1.5);

    // Usporedite tjedne operatorima == i <, zamijenite ih s swap i ponovno ispišite ukupne sate
    if (tjedan1 == tjedan2) {
        cout << "Tjedni su jednaki.\n";
    }
    else {
        cout << "Tjedni nisu jednaki.\n";
    }

    if (tjedan1 < tjedan2) {
        cout << "Tjedan 1 je manji (u leksikografskom smislu) od Tjedna 2.\n";
    }
    else {
        cout << "Tjedan 1 nije manji od Tjedna 2.\n";
    }

    // Zamjena sadržaja
    tjedan1.swap(tjedan2);
    cout << "Nakon swap-a, ukupan broj sati 1. tjedna: " << total(tjedan1) << "\n";
    cout << "Nakon swap-a, ukupan broj sati 2. tjedna: " << total(tjedan2) << "\n";

    return 0;
}