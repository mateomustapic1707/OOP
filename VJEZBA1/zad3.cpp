#include <iostream>
#include <cmath> // za abs

using namespace std;

int& find_max(int arr[], int n) {
    int max_idx = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[max_idx]) {
            max_idx = i;
        }
    }
    return arr[max_idx];
}

int main() {
    int numbers[] = { 4, -7, 12, 0, 9, -3 };
    int n = sizeof(numbers) / sizeof(numbers[0]);

    // Ispis pocetnog niza
    cout << "Pocetni niz: ";
    for (int x : numbers) {
        cout << x << " ";
    }
    cout << endl;

    // Zamjena svakog negativnog elementa njegovom apsolutnom vrijednoscu
    for (int& x : numbers) { //sluzi kako bi mijenjali originalne elemente
        if (x < 0) {
            x = abs(x);
        }
    }

    cout << "Niz nakon abs vrijednosti: ";
    for (int x : numbers) {
        cout << x << " ";
    }
    cout << endl;

    // Koristimo povratnu vrijednost kao lvalue i postavljamo najveci element na 0
    find_max(numbers, n) = 0;

    cout << "Niz nakon postavljanja max elementa na 0: ";
    for (int x : numbers) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}