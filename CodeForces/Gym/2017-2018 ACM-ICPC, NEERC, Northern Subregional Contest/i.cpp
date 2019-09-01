#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define INF 1e9
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> ii;

int n;

int main()
{
	// ios_base::sync_with_stdio(false);	 cin.tie(0);
	#ifndef LOCAL
        freopen("intel.in", "r", stdin);
        freopen("intel.out", "w", stdout);
    #endif

    ii maxxi = {-INF,-INF}; 
    ii minni = {INF,INF};

    scanf("%d",&n);

    vector<ii> point(n+1);

    for(int i=0;i<n;++i)
    {
    	scanf("%lld%lld",&point[i].x,&point[i].y);

    	if(maxxi.x<point[i].x) maxxi.x = point[i].x; // maiores pontos
    	if(maxxi.y<point[i].y) maxxi.y = point[i].y;

    	if(minni.x>point[i].x) minni.x = point[i].x; // menores pontos
    	if(minni.y>point[i].y) minni.y = point[i].y;
    }

    ll ans = 0;

    point[n] = point[0];

    for(int i=0;i<n;++i)
    	ans += abs(point[i+1].x - point[i].x) + abs(point[i+1].y - point[i].y);
	
	ans -= 2*(maxxi.x - minni.x) + 2*(maxxi.y - minni.y);

	printf("%lld\n",ans);
	
}