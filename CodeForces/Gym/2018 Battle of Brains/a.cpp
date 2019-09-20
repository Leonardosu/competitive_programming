#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int T, N, A, B, C, D;
	
	cin >> T;
	
	for (int t=0; t<T; t++) {
		cin >> N >> A >> B >> C >> D;
		N+=2;
		
		int prizes = A + B + C + D;
		
		if (prizes >= N/2) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
		
	}
	return 0;
}