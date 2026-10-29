#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string jmbag;
    string surname;
    int points;
};

int main() {
    vector<Student> registered = {
        {"0302", "Kovac", 78}, {"0117", "Babic", 45},
        {"0255", "Maric", 91}, {"0117", "Babic", 45},
        {"0410", "Novak", 78}, {"0089", "Juric", 62},
        {"0255", "Maric", 91}, {"0520", "Maric", 55},
        {"0333", "Peric", 30}
    };


    sort(registered.begin(), registered.end(), [](const Student& a, const Student& b) {
        return a.jmbag < b.jmbag;
        });


    auto it_unique = unique(registered.begin(), registered.end(), [](const Student& a, const Student& b) {
        return a.jmbag == b.jmbag;
        });
    registered.erase(it_unique, registered.end());

    cout << "prijavljenih: " << registered.size() << "\n";


    int prag;
    cout << "Prag: ";
    cin >> prag;


    registered.erase(
        remove_if(registered.begin(), registered.end(), [prag](const Student& s) {
            return s.points < prag;
            }),
        registered.end()
    );


    sort(registered.begin(), registered.end(), [](const Student& a, const Student& b) {
        if (a.points != b.points) {
            return a.points > b.points; 
        }
        return a.surname < b.surname;    
        });

    int rbr = 1;
    for (const auto& s : registered) {
        cout << rbr++ << ". " << s.surname << " (" << s.jmbag << ") " << s.points << "\n";
    }

    return 0;
}