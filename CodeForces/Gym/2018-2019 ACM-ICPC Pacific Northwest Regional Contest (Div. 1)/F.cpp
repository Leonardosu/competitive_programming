/*
Problem: F - Rectangles
Link: https://codeforces.com/gym/101982/problem/F
Complexity: O(N * Log(K) + N * Log (N))
Solution: Sweep Line with Sparse Segment Tree using 
Author: Carlos Eduardo (eduardocesb)
*/
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 100000010
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101 
#define MAXN 1000000010
#define MAXL 23
#define endl '\n'
 
using namespace std;
 
struct Node
{
	Node *l, *r;
 
	int a, b, inv, sum;
 
	Node (int x, int y)
	{
		l = r = NULL;
		inv = sum = 0;
		a = x;
		b = y;
 
	}
 
	void lazy()
	{
		if (!inv) return;
 
		sum = ((b - a) + 1) - sum;
 
		if (a != b)
		{
			int mid = (a + b) / 2;
 
			if (!l) l = new Node(a, mid);
			if (!r) r = new Node(mid + 1, b);
 
			l->inv = !l->inv;
			r->inv = !r->inv;
		}
 
		inv = 0;
	}
 
	void update(int x, int y)
	{
		lazy();
 
		if (y < a || b < x) return;
 
		if(x <= a && b <= y)
		{
			inv = !inv;
			lazy();
			return;	
		}
 
		int mid = (a + b) / 2;
 
		if (!l) l = new Node(a, mid);
		if (!r) r = new Node(mid + 1, b);
 
		l->update(x, y);
		r->update(x, y);
 
		sum = l->sum + r->sum;
	}
	
	int query(int x, int y)
	{
		lazy();
 
		if (y < a || b < x) return 0;
 
		if(x <= a && b <= y)
			return sum;
 
		int mid = (a + b) / 2;
 
		if (!l) l = new Node(a, mid);
		if (!r) r = new Node(mid + 1, b);
 
		return l->query(x, y) + r->query(x, y);
	}
};
 
struct Event
{
	int i, l, r;
 
	Event(int i, int l, int r) : i(i), l(l), r(r) {}
 
	bool operator < (const Event &a) const
	{
		return i < a.i;
	}
};
 
vector<Event> events;
 
int main(int argc, char** argv)
{
	optimize;
 
	int N, x1, y1, x2, y2;
 
	cin >> N;
 
	Node *root = new Node(0, MAXN);
 
	for (int i = 0; i < N; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
 
		events.EB(x1, y1, y2);
		events.EB(x2, y1, y2);
	}
 
	sort(ALL(events));
 
	ll last = 0, ans = 0;
 
	for (int i = 0; i < events.size();)
	{
		int curr = events[i].i;
 
		ans += (root->query(0, MAXN) * (curr - last));
 
		while (i < events.size() && events[i].i == curr)
		{
			root->update(events[i].l + 1, events[i].r);
			i++;
		}
 
		last = curr;
	}
 
	cout << ans << endl;
 
	return 0;
}