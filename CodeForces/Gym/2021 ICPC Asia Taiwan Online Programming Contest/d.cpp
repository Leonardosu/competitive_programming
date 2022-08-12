#include <bits/stdc++.h>
using namespace std;

long double dp[310];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    dp[1]=1;
    for (int i=2; i<=n; i++){
        dp[i]+=1.0/(n-1);
        for (int j=2; j<i; j++){
            dp[i]+=dp[j]*(1.0/(n-j+1));
        }
    }
    cout<<setprecision(10)<<dp[n]<<endl;
}
