#include <iostream>
#include <vector>

using namespace std;

void input_vector(vector<int>& v) {
	int broj;
	cout << "Unesite brojeve (0 za prekid): \n";
	while (cin >> broj && broj != 0) {
		v.push_back(broj);
	}
}

void print_vector(const vector<int>& v) {
	for (int x : v) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	vector<int>(moj_vektor);
	input_vector(moj_vektor);

	cout << "Unesite vektor: ";
	print_vector(moj_vektor);

	cout << "Vektor obrnuto: ";
	for (auto it = moj_vektor.rbegin(); it != moj_vektor.rend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	cout << endl;

	cout << "Dodavanje brojeva od 1 do 20\n";
	vector<int> v_prvi;;
	for (int i = 0; i <= 20; ++i) {
		v_prvi.push_back(i);
		cout << "Element vektora (i): " << i << ", velicina vektora: " << v_prvi.size() << ", kapacitet vektora:" << v_prvi.capacity() << "\n\n";
	}

	cout << endl;

	cout << "Dodavanje brojeva od 1 do 20 sa reserve(100)\n";

	vector<int> v_rezerviran;
	v_rezerviran.reserve(100);
	for (int i = 0; i <= 20; ++i) {
		v_rezerviran.push_back(i);
		cout << "Element vektora (i): " << i << ", velicina vektora: " << v_rezerviran.size() << ", kapacitet vektora:" << v_rezerviran.capacity() << "\n\n";
	}

	v_rezerviran.shrink_to_fit();

	cout << "Kapacitet nakon shrink_to_fit: " << v_rezerviran.capacity() << endl;

	return 0;
}