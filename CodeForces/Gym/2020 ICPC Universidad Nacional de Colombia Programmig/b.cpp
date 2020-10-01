#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

template <class T>
class SuffixArray {
public:
	std::vector<int> buildSuffix(const std::vector<T> &array) {
		int n = array.size();
		std::vector<int> sa(n);
		for(int i = 0; i < n; i++) {
			sa[i] = i;
		}
		std::sort(sa.begin(), sa.end(), [&](int a, int b) { return array[a] < array[b]; });
		int cur = 0;
		std::vector<int> inv(n);
		std::vector<int> nxt(n);
		inv[sa[0]] = 0;
		for(int i = 1; i < n; i++) {
			inv[sa[i]] = (array[sa[i - 1]] != array[sa[i]] ? ++cur : cur);
		}
		cur++;
		for(int k = 0; cur < n; k++) {
			cur = 0;
			auxSort(sa, inv, 1 << k);
			for(int l = 0, r = 0; l < n; l = r, cur++) {
				while(r < n && getPair(inv, sa[l], 1 << k) == getPair(inv, sa[r], 1 << k)) {
					nxt[sa[r++]] = cur;
				}
			}
			nxt.swap(inv);
		}
		return sa;
	}
	
private:
	void auxSort(std::vector<int> &sa, const std::vector<int> &inv, int offset) {
		// O(nlogn) step, O(nlog^2n) total
		std::sort(sa.begin(), sa.end(), [&](int a, int b) { return getPair(inv, a, offset) < getPair(inv, b, offset); });
		// O(n) step, O(nlogn) total -- TO DO --
	}
	std::pair<int, int> getPair(const std::vector<int> &inv, int pos, int offset) {
		return std::pair<int, int>(inv[pos], pos + offset < inv.size() ? inv[pos + offset] : -1);
	}
};


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string xx,yy;
	cin>>xx>>yy;
	SuffixArray<char> SA;
	vector<char> s1,s2;

	for(auto &c : xx) s1.pb(c);
	for(auto &c : yy) s2.pb(c);

	auto sufixo1 = SA.buildSuffix(s1);
	auto sufixo2 = SA.buildSuffix(s2);
	int i = sufixo1.back();
	int j = sufixo2.back();

	string ans = "";
	ans.pb(xx[i]);
	i++;
	while(i < xx.size() && xx[i]>=yy[j])
		ans.pb(xx[i]),i++;
	for(;j<yy.size();++j)
		ans.pb(yy[j]);
		
	cout<<ans<<"\n";
}