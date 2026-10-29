#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool starts_with(const string& s, const string& prefix) {
	if (prefix.length() > s.length()) {
		return false;
	}
	return equal(prefix.begin(), prefix.end(), s.begin());
}

bool ends_with(const string& s, const string& suffix) {
	if (suffix.length() > s.length()) {
		return false;
	}
	return equal(suffix.rbegin(), suffix.rend(), s.rbegin());
}

int main() {
	vector<string> datoteke = {
		"vjezba04.cpp", 
		"slajdovi.pdf", 
		"man.cpp", 
		"README.md", 
		"vjezba04.h", 
		"notes.txt", 
		"vjezba03.cpp"
	};

	int brojac_cpp = 0;
	for (const auto& d : datoteke) {
		if (ends_with(d, ".cpp")) {
			brojac_cpp++;
		}
	}

	cout << ".cpp datoteka: " << brojac_cpp << "\n";

	datoteke.erase(
		remove_if(datoteke.begin(), datoteke.end(), [](const string& d) {
			return starts_with(d, "vjezba");
		}),
		datoteke.end());
	for (const auto& d : datoteke) {
		cout << d << " ";
	}
	cout << "\n\n";

	return 0;
}