#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
};

// Funkcije s pointerima (C stil)
void move_by(Point* p, double dx, double dy) {
    p->x += dx;
    p->y += dy;
}

double dist(const Point* a, const Point* b) {
    return sqrt(pow(b->x - a->x, 2) + pow(b->y - a->y, 2));
}

// Funkcije s referencama (C++ stil)
void move_by(Point& p, double dx, double dy) {
    p.x += dx;
    p.y += dy;
}

double dist(const Point& a, const Point& b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int main() {
    Point p1{ 1.0, 2.0 };
    Point p2{ 4.0, 6.0 };

    // Pozivi s pointerima (moramo slati adrese sa &)
    move_by(&p1, 1.0, 1.0);
    cout << "Udaljenost (pointeri): " << dist(&p1, &p2) << endl;

    // Pozivi s referencama (šaljemo direktno objekte)
    move_by(p1, 1.0, 1.0);
    cout << "Udaljenost (reference): " << dist(p1, p2) << endl;

    // Niz od pet točaka - traženje najbliže ishodištu (0, 0)
    Point tocke[5] = {
        {3.0, 4.0},
        {1.0, 1.0},
        {5.0, 2.0},
        {-0.5, 0.5},
        {2.0, 2.0}
    };

    Point ishodiste{ 0.0, 0.0 };
    int najbliza_idx = 0;
    double min_dist = dist(tocke[0], ishodiste);

    for (int i = 1; i < 5; ++i) {
        double d = dist(tocke[i], ishodiste);
        if (d < min_dist) {
            min_dist = d;
            najbliza_idx = i;
        }
    }

    cout << "Najbliza tocka ishodistu: ("
        << tocke[najbliza_idx].x << ", " << tocke[najbliza_idx].y
        << ") s udaljenoscu " << min_dist << endl;

    return 0;
}