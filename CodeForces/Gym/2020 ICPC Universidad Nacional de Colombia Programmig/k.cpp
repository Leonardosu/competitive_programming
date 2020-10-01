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



int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string a,b,ans;
    ans = "=";
    cin>>a>>b;

    if(a == b)
    {
        cout<<"=\n";
        return 0;
    }

    for(int i=0;i<min(a.size(),b.size());++i)
    {

        if(isalpha(a[i]))
        {
            if(a[i] > b[i])
            {
                ans = '>';
                break;
            }
            else if(a[i] < b[i])
            {
                ans = '<';
                break;
            }
        }
        else
        {
            string num1="",num2="";

            for(int j=i;j<a.size();++j)
            {
                // if(isalpha(a[i])) break;
                num1.pb(a[j]);
            }

            for(int j=i;j<b.size();++j)
            {
                // if(isalpha(b[i])) break;
                num2.pb(b[j]);
            }


            if(num1.size() == num2.size())
            {
                ans = "=";
                for(int j=0;j<num1.size();++j)
                {
                    if(num1[j] > num2[j])
                    {
                        ans = '>';
                        break;
                    }
                    else if(num1[j] < num2[j])
                    {
                        ans = '<';
                        break;
                    }
                }
            }
            else if(num1.size() < num2.size()) ans = "<";
            else ans = ">";
            break;
        }
        
    }

    
    cout<<ans<<"\n";
}