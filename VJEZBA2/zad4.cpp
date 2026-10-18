#include <iostream>

using namespace std;

void my_transform(int arr[], int n, int (*f)(int)) {
    for (int i = 0; i < n; ++i) {
        arr[i] = f(arr[i]);
    }
}

int twice(int x) {
    return x * 2;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = 5;

    my_transform(arr, n, twice);

    my_transform(arr, n, [](int x) -> int {
        return (x % 2 == 0) ? x / 2 : x * 2;
        });

    int suma = 0;
    int produkt = 1;
    for (int i = 0; i < n; ++i) {
        [&](int val) {
            suma += val;
            produkt *= val;
            }(arr[i]);
    }

    int prag = 3;
    int suma_vecih = 0;
    for (int i = 0; i < n; ++i) {
        [prag, &suma_vecih](int val) {
            if (val > prag) suma_vecih += val;
            }(arr[i]);
    }

    cout << "Suma: " << suma << ", Produkt: " << produkt << endl;
    cout << "Suma vecih od " << prag << ": " << suma_vecih << endl;

    return 0;
}