// Vjezba 5, zadatak 3: napisite strukturu Song i klasu Album iznad main.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Song {
    string title;
    string artist;
    int seconds;
};

class Album {
    string title;
    int year;
    vector<Song> songs;

public:
    // Konstruktor prima naziv, godinu i prvu obaveznu pjesmu (invarijanta: album nije prazan)[cite: 4]
    Album(string t, int y, Song first) : title(t), year(y) {
        songs.push_back(first);
    }

    // Dodaje pjesmu ako album već nema pjesmu istog naslova[cite: 4]
    bool add(Song s) {
        for (const auto& song : songs) {
            if (song.title == s.title) {
                return false; // Već postoji pjesma s tim naslovom
            }
        }
        songs.push_back(s);
        return true;
    }

    // Vraća ukupno trajanje u sekundama[cite: 4]
    int duration() const {
        int total = 0;
        for (const auto& song : songs) {
            total += song.seconds;
        }
        return total;
    }

    // Ispisuje album i popis pjesama u traženom formatu[cite: 4]
    void print() const {
        int total_sec = duration();
        int mins = total_sec / 60;
        int secs = total_sec % 60;

        cout << title << " (" << year << "), " << songs.size() << " pjesme, "
            << mins << ":" << (secs < 10 ? "0" : "") << secs << "\n";

        for (size_t i = 0; i < songs.size(); ++i) {
            cout << "  " << (i + 1) << ". " << songs[i].title << "\n";
        }
    }
};

int main()
{
    Album a("Sol Invictus", 2015, { "Sol Invictus", "Faith No More", 156 });
    a.add({ "Superhero", "Faith No More", 315 });
    a.add({ "Matador", "Faith No More", 368 });
    std::cout << a.add({ "Superhero", "Faith No More", 315 }) << '\n';    // vec postoji[cite: 5]
    a.print();
    return 0;
}

/*
Ocekivani ispis:

    0
    Sol Invictus (2015), 3 pjesme, 13:59
      1. Sol Invictus
      2. Superhero
      3. Matador
*/