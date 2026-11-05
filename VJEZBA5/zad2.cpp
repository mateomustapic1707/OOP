#include <iostream>
#include <string>

using namespace std;

class Clip {
    int start;
    int end;
    int length;
    string name;
    const int max_length;

public:
    Clip(const string& name, int s, int e)
        : start(s), end(e), length(e - s), max_length(600)
    {
        this->name = name;  //Liva strana je ?lan klase, desna je parametar
    }

    void print() const {
        cout << name << ": " << length << " s\n";
    }
};

int main() {
    Clip c("Concrete (Shame)", 10, 190);
    c.print();
    return 0;
}