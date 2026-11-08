// Vjezba 5, zadatak 6: napisite klasu Coin iznad funkcije bonus.

#include <iostream>

using namespace std;

class Coin {
    int value;
    static int counter; // Statički brojač aktivnih novčića

public:
    // Konstruktor postavlja vrijednost i povećava brojač
    Coin(int v) : value(v) {
        counter++;
    }

    // Destruktor se poziva kad novčić izađe iz dosega i smanjuje brojač
    ~Coin() {
        counter--;
    }

    // Statička metoda koja vraća broj novčića koji trenutno postoje
    static int remaining() {
        return counter;
    }
};

// Inicijalizacija statičkog člana izvan klase
int Coin::counter = 0;

void bonus()             // bonus runda: tri novcica
{
    Coin c1(5);
    Coin c2(5);
    Coin c3(10);
    cout << Coin::remaining() << '\n';
}

int main()
{
    cout << Coin::remaining() << '\n';
    Coin gold(50);
    {
        Coin a(1);
        Coin b(1);
        cout << Coin::remaining() << '\n';
    } // ovdje a i b izlaze iz dosega, pozivaju im se destruktori i brojač se smanjuje za 2
    cout << Coin::remaining() << '\n';
    bonus(); // unutar funkcije stvore se 3, ispiše se 4, a nakon izlaska iz funkcije oni se uništavaju
    cout << Coin::remaining() << '\n';
    return 0;
}
