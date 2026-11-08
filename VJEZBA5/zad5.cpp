// Vjezba 5, zadatak 5: napisite klasu Ticket iznad main.

#include <iostream>
#include <string>

using namespace std;

class Ticket {
    string concert;
    int id;
    static int counter;

public:

    Ticket(const string& concert_name) : concert(concert_name) {
        counter++;
        id = counter;
    }

    int get_id() const {
        return id;
    }

    static int issued() {
        return counter;
    }
};

int Ticket::counter = 0;

int main()
{
    cout << Ticket::issued() << '\n';
    Ticket t1("Shame, Zagreb");
    Ticket t2("Shame, Zagreb");
    Ticket t3("Viagra Boys, Ljubljana");
    cout << t1.get_id() << ' ' << t2.get_id() << ' ' << t3.get_id() << '\n';
    cout << Ticket::issued() << '\n';
    return 0;
}