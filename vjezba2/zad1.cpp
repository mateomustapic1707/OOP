#include <iostream>
#include <string>
using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b));

inline int my_max(int a, int b) {
	return (a > b) ? a : b;
}

template<typename T>
inline T my_max_tmpl(T a, T b) {
	return (a > b) ? a : b;
}

int main() {
	int a = MAX(3, 5);
	int b = 2 * MAX(3, 5);
	int c = MAX(3, 5) + 1;
	int i = 3;
	i = 3;
	int rez_inline = my_max(++i, 2);
	cout << "Rezultat:" << rez_inline << " nakon poziva:" << i << endl;
	cout << "Int max: " << my_max_tmpl(10, 20) << endl;
	cout << "Double max:" << my_max_tmpl(5.5, 7.5) << endl;
	cout << "Char max: " << my_max_tmpl('a', 'm') << endl;
	cout << "String max: " << my_max_tmpl(string("Ivan"), string("Ana")) << endl;
	return 0;
}