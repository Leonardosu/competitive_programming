#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> point;


vector<point> p[4];
ll dist(point a,point b)
{
	ll xx = a.x - b.x, yy = a.y - b.y;
	return xx*xx + yy*yy;
}

point rotate_ccw(point a,point center)
{
	// a.x-=center.x;
	// a.y-=center.y;	
	return { -(a.y - center.y) + center.x, (a.x - center.x) + center.y };
}

bool is_square(point a, point b, point c, point d)
{	
	// if(a == b || a == c || a == d || b == c || b == d || c == d) return false;
	ll d2 = dist(a,b);
	ll d3 = dist(a,c);
	ll d4 = dist(a,d);

	if(d2 == 0 || d3 == 0 || d4 == 0) return false;

	if(d2 == d3 && 2LL * d2 == d4 && 2LL * dist(b, d) == dist(b, c)) 
		return true; 
      
    if(d3 == d4 && 2LL * d3 == d2 && 2LL * dist(c, b) == dist(c, d))
        return true; 
    
    if(d2 == d4 && 2LL * d2 == d3 && 2LL * dist(b, c) == dist(b, d))
        return true; 
    

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
		
	cin>>t;
	while(t--)
	{		
		point now,center;
		for(int i=0;i<4;++i)
		{
			cin>>now.x>>now.y>>center.x>>center.y;
			p[i].resize(4);
			p[i][0] = now;
			p[i][1] = rotate_ccw(p[i][0],center);
			p[i][2] = rotate_ccw(p[i][1],center);
			p[i][3] = rotate_ccw(p[i][2],center);
		}

		int ans = 123;
		int qnt = 0;
		for(int i=0;i<4;++i)
			for(int j=0;j<4;++j)
				for(int k=0;k<4;++k)
					for(int l=0;l<4;++l)					
						if(i + j + k + l < ans && is_square(p[0][i], p[1][j], p[2][k], p[3][l]))						
							ans = i + j + k + l;
						

		// cout<<qnt<<"\n";
		if(ans == 123) ans = -1;
		cout<<ans<<"\n";
	}
	
}
