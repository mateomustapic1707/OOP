#include <iostream>
#include <string>

using namespace std;

struct Student {
    string ime;
    string jmbag;
    int godina_studija;
    int ects;
    double prosjek;
};

void filter_students(Student s[], int n, void (*action)(Student&), bool (*cond)(const Student&)) {
    for (int i = 0; i < n; ++i) {
        if (cond(s[i])) {
            action(s[i]);
        }
    }
}

// Akcija za ispis studenta
void ispisi_studenta(Student& s) {
    cout << s.ime << " (" << s.jmbag << ") - Godina: " << s.godina_studija
        << ", ECTS: " << s.ects << ", Prosjek: " << s.prosjek << endl;
}

// Akcija za povecanje godine studija
void povecaj_godinu(Student& s) {
    s.godina_studija++;
}

int main() {
    Student studenti[] = {
        {"Ana", "0036123456", 1, 15, 3.8},
        {"Ivan", "0036654321", 2, 50, 3.2},
        {"Maja", "0036987654", 1, 0, 4.1},
        {"Luka", "0036456789", 3, 48, 3.6}
    };
    int n = 4;

    cout << "1. Studenti 1. godine s barem 1 polozenim ispitom (ECTS > 0):" << endl;
    filter_students(studenti, n, ispisi_studenta, [](const Student& s) {
        return s.godina_studija == 1 && s.ects > 0;
        });

    cout << "\n2. Studenti s prosjekom vecim od 3.5:" << endl;
    filter_students(studenti, n, ispisi_studenta, [](const Student& s) {
        return s.prosjek > 3.5;
        });

    cout << "\n3. Povecanje godine studija za ECTS >= 45..." << endl;
    filter_students(studenti, n, povecaj_godinu, [](const Student& s) {
        return s.ects >= 45;
        });

    cout << "\nStanje nakon povecanja godine:" << endl;
    for (const auto& s : studenti) {
        cout << s.ime << " - Godina: " << s.godina_studija << endl;
    }

    return 0;
}