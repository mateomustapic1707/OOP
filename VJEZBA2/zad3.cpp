#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


template <typename T>
inline bool ascending(T a, T b) {
    return a > b;
}

template <typename T>
inline bool descending(T a, T b) {
    return a < b;
}


template <typename T>
void my_sort(T arr[], int n, bool (*cmp)(T, T)) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (cmp(arr[j], arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr_int[] = { 4, 1, 3 };
    double arr_double[] = { 3.14, 1.41, 2.71 };
    char arr_char[] = { 'c', 'a', 'b' };

    my_sort(arr_int, 3, ascending<int>);
    my_sort(arr_double, 3, descending<double>);
    my_sort(arr_char, 3, ascending<char>);

    cout << "Sorted double (descending): ";
    for (double d : arr_double) cout << d << " ";
    cout << endl;

    return 0;
}