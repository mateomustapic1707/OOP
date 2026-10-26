#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Song {
	string title;
	string artist;
	int year;
	int plays;

};

void print_song(const Song& s) {
	cout << "Naslov: " << s.title << ", ";
	cout << "Izvodac: " << s.artist << ", ";
	cout << "Godina: " << s.year << ", ";
	cout << "Slusanja: " << s.plays << endl;

}

int main() {
	vector<Song>lista = {
	{"Today", "Beyonce", 2005, 10000},
	{"Love me more", "Beyonce", 1998, 20000},
	{"Die with you", "Madona", 1992, 50000},
	{"Go lower", "Madona", 1989, 45000},
	{"NGL", "XXX", 2001, 60000},
	{"DMASKA", "XXX", 2005, 70000}
	};

	sort(lista.begin(), lista.end(), [](const Song& a, const Song& b) {
		if (a.year != b.year) {
			return a.year < b.year;
		}
		return a.title < b.title;
	});

	cout << "SORTIRANA LISTA" << endl;
	for (const auto& s : lista) {
		print_song(s);
	}
	cout << "\n";

	string izvodac;
	cout << "Unesite ime izvodaca: ";
	getline(cin, izvodac);

	int brojac = 0;
	const Song *najstarija = nullptr;

	for (const auto& s : lista) {
		if (s.artist == izvodac) {
			brojac++;
			if (najstarija == nullptr) {
				najstarija = &s;
			}
		}
	}

	if (brojac > 0) {
		cout << "Broj pjesama izvodaca " << izvodac << ": " << brojac << "\n";
		cout << "Najstarija pjesma: \n";
		print_song(*najstarija);
	}
	else {
		cout << "Izvodac " << izvodac << " nije na listi\n";
	}

	cout << "\n";

	if (!lista.empty()) {
		auto najslusanija = lista.begin();
		for (auto it = lista.begin(); it != lista.end(); ++it) {
			if (it->plays > najslusanija->plays) {
				najslusanija = it;
			}
		}
		cout << "Najslusanija pjesma: \n";
		print_song(*najslusanija);
	}
	return 0;
}