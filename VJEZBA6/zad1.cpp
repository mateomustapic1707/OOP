#include <iostream>

using namespace std;

class IntStack {
	int *data;
	int sz;
	int cap;
public:
	IntStack(int initial_cap = 2) : sz(0), cap(initial_cap) {
		data = new int[cap];
	}
	IntStack(const IntStack& other) : sz(other.sz), cap(other.cap) {
		data = new int[cap];
		for (int i = 0; i < sz; ++i) {
			data[i] = other.data[i];
		}
	}
	~IntStack() {
		delete[] data;
	}
	void push(int x) {
		if (sz == cap) {
			cap *= 2;
			int *new_data = new int[cap];
			for (int i = 0; i < sz; ++i) {
				new_data[i] = data[i];
			}
			delete[] new_data;
			data = new_data;
		}
		data[sz++] = x;
	}

	void pop() {
		if (sz > 0) {
			sz--;
		}
	}

	int top() const {
		return data[sz - 1];
	}
	bool empty() const {
		return sz == 0;
	}
	int size() const {
		return sz;
	}
	int capacity() const {
		return cap;
	}
};



int main()
{
	IntStack s;
	for (int i = 1; i <= 5; ++i)
		s.push(i * 10);
	std::cout << s.size() << ' ' << s.capacity() << ' ' << s.top() << '\n';
	IntStack c = s;     
	c.pop();
	c.push(99);
	std::cout << s.top() << ' ' << c.top() << '\n';
	while (!s.empty()) { std::cout << s.top() << ' '; s.pop(); }
	std::cout << '\n';
	return 0;
}