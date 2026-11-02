#include <iostream>
#include <cassert>

using namespace std;

class Volume {
private:
	int vol;
	int prev_vol;
	bool muted;

	static int function(int L) {
		if (L < 0) return 0;
		if (L > 100) return 100;
		return L;
	}

	bool valid() const {
		return vol >= 0 && vol <= 100;
	}

public:
	Volume(int L) : vol(function(L)), prev_vol(vol), muted(false) {
		assert(valid());
	}

	Volume(): Volume(50) {};

	int get() const {
		return muted ? 0 : vol;
	}
	void up(int step = 10) {
		if (muted) {
			muted = false;
		}
		vol = function(vol + step);
		assert(valid());
	}

	void down(int step = 10) {
		if (muted) {
			muted = false;
		}
		vol = function(vol - step);
		assert(valid());
	}
	void mute() {
		if (!muted) {
			prev_vol = vol;
			vol = 0;
			muted = true;
		}
		assert(valid());
	}

	void unmute() {
		if (muted) {
			vol = prev_vol;
			muted = false;
		}
		assert(valid());
	}
};



int main()
{
	Volume v;
	cout << v.get() << '\n';
	v.up();
	v.up(60);
	cout << v.get() << '\n';
	v.mute();
	cout << v.get() << '\n';
	v.unmute();
	cout << v.get() << '\n';
	Volume w(-20);
	w.down();
	cout << w.get() << '\n';
	return 0;
}

/*
Ocekivani ispis:
   50
   100
   0
   100
   0
*/