#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve_task() {
	auto toSeconds = [&](string &s) {
		ll seconds = stoi(s.substr(6, 2));
		seconds += stoi(s.substr(3, 2)) * 60;
		seconds += stoi(s.substr(0, 2)) * 60 * 60;
		return seconds;
	};
	auto getDistance = [&](string &a, string &b, ll speed) {
		return (double) (toSeconds(a) - toSeconds(b)) * speed / 3600.0;
	};

	string lastTime = "00:00:00";
	int lastSpeed = 0;
	string input;
	cout<<fixed<<setprecision(2);
	double traveled = 0;
	while(getline(cin, input)) {
		string time = input.substr(0, 8);
		int speed = -1;
		if(sz(input) > 8) {
			traveled += getDistance(time, lastTime, lastSpeed);
			speed = stoi(input.substr(8, sz(input)));
			lastTime = time;
		}

		if(speed == -1) {
			traveled += getDistance(time, lastTime, lastSpeed);
			cout<<time<<" "<<traveled<<" km\n";
		} else {
			lastSpeed = speed;
		}
		lastTime = time;
	}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    // cin>>T_T;
    while(T_T--)
        solve_task();
}