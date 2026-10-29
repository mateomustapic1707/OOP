#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

struct PasswordInfo {
	int length;
	int digits;
	int uppercase;
	int special;
};

PasswordInfo analyze(const string& password) {
	PasswordInfo info;
	info.length = password.length();

	info.digits = count_if(password.begin(), password.end(), [](unsigned char c) {
		return isdigit(c);
	});

	info.uppercase = count_if(password.begin(), password.end(), [](unsigned char c) {
		return isupper(c);
	});
	info.special = count_if(password.begin(), password.end(), [](unsigned char c) {
		return ispunct(c);
	});
	return info;
}

bool is_strong(const PasswordInfo& info) {
	return (info.length >= 10 && info.digits >= 1 && info.uppercase >= 1 && info.special >= 1);
}

int main() {
	string unos = "Lozinka123!";
	PasswordInfo inf = analyze(unos);

	cout << unos << ": duljina " << inf.length << ", znamenke " << inf.digits << ", velika " << inf.uppercase << ", posebni " << inf.special << " : ";
	if (is_strong(inf)) {
		cout << "jaka lozinka";
	}
	else {
		cout << "slaba lozinka";
	}
	return 0;
}