#include <iostream>
#include <algorithm>

using namespace std;

inline bool ascending(int a, int b) {
	return a > b;
}

inline bool descending(int a, int b) {
	return a < b;
}

void my_sort(int arr[], int n, bool (*cmp)(int, int)) {
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (cmp(arr[j], arr[j + 1])) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int main() {
	int arr[] = { 5,2,8,1,4 };
	int n = 5;

	my_sort(arr, n, ascending);
	cout << "Ulazno: " << endl;
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	my_sort(arr, n, descending);
	cout << "Silazno: " << endl;
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}