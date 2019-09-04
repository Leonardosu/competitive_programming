#include <bits/stdc++.h> // UVA 11057 - Exact Sum
using namespace std; 	//O(NLogN) Binary Search

int n,val;
vector<int> books;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	while(cin>>n)
	{
		books.clear();
		for(int i=0;i<n;++i)
		{
			cin>>val; books.push_back(val);
		}

		sort(books.begin(),books.end());
		cin>>val;

		int x = 2000001, y = 8000001;

		for(int i=0;i<books.size();++i)
		{
			int z = books[i];
			int l = 0, r = n - 1;

			while(l<=r)
			{
				int mid = (l+r)/2;
				if(z + books[mid] == val && (mid != i))
				{
					if(abs(books[mid] - z)< abs(y-x))
						x = min(z,books[mid]),y = val - x;
					break;
				}

				if(z + books[mid] < val)
					l = mid + 1;
				else
					r = mid - 1;
			}
		}
		cout<<"Peter should buy books whose prices are "<<x<<" and "<<y<<".\n\n";
	}
}