#include <bits/stdc++.h>
#define f first
#define s seccond
#define pb pus_back
#define mp make_pair
using namespace std;
 
typedef long long int ll;
typedef pair<int,int> ii;
 
const int MAXN = 200200;
 
set<long long int> values;
 
int main()
{
	int N;
	scanf(" %d", &N);
 
	long long tmp;
	for (int i = 0; i < N; i++) {
		scanf(" %lld", &tmp);
		values.insert(tmp);
	}
 
	printf("%lu\n", N - values.size());
 
	return 0;
}