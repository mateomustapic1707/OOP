#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void inp(vector<int>& v) {
    int x;
    cout << "Brojevi (0 kraj): ";
    while (cin >> x && x != 0) v.push_back(x);
}

void prn(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << "\n";
}

int main() {
    vector<int> v;
    inp(v);
    if (v.empty()) { cout << "Prazno!\n"; return 0; }

    int k;
    cout << "k: ";
    cin >> k;

    // 1. Negativni brojevi
    cout << "negativnih: " << count_if(v.begin(), v.end(), [](int x) { return x < 0; }) << "\n";

    // 2. Prvi višekratnik
    auto it = find_if(v.begin(), v.end(), [k](int x) { return x % k == 0; });
    if (it != v.end())
        cout << "prvi višekratnik od " << k << ": " << *it << " (pozicija " << distance(v.begin(), it) << ")\n";
    else
        cout << "prvi višekratnik od " << k << ": nema\n";

    // 3. Min i max (kompatibilno sa svim verzijama)
    auto mm = minmax_element(v.begin(), v.end());
    cout << "min " << *mm.first << " (pozicija " << distance(v.begin(), mm.first)
        << "), max " << *mm.second << " (pozicija " << distance(v.begin(), mm.second) << ")\n";

    // 4. Uklanjanje višekratnika
    v.erase(remove_if(v.begin(), v.end(), [k](int x) { return x % k == 0; }), v.end());

    cout << "bez višekratnika: ";
    prn(v);

    return 0;
}