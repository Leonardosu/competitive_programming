#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> factorize(long long int N) 
{
    vector<int> ret;
    ret.push_back(1);
 
    if (N > 100 * 100) 
    {
        ret.push_back(N);
        N = 1;
    }
 
    for (int i = 2; N != 1; i++) 
    {
        while (N%i == 0) 
        {
            ret.push_back(i);
            N /= i;
        }
    }
    return ret;
}
 
int minsize(int N) 
{
    return (N * 2) - 1;
}
 
bool isPossible(int H, int W, vector<int> &factors, pair<int, int> &res) 
{
    long long int total = 1;
    for (int i : factors) 
    {
        total *= i;
    }
 
    do {
        long long int curr = 1;
        for (int i : factors) 
        {
            curr *= i;
            res.first = curr;
            res.second = total/curr;
            if (minsize(curr) <= H && minsize(total/curr) <= W) {
                return true;
            }
 
            res.first = total/curr;
            res.second = curr;
            if (minsize(total/curr) <= H && minsize(curr) <= W) {
                return true;
            }
        }
        
    } while(next_permutation(factors.begin(), factors.end()));
    
    return false;
}
 
void printres(int h, int w, int l, int c) 
{
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (((i < l * 2 - 1) && i & 1) 
            ||  ((j < c * 2 - 1) && j & 1)) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}
 
int main() 
{
    #ifndef LOCAL
        freopen("kotlin.in", "r", stdin);
        freopen("kotlin.out", "w", stdout);
    #endif
 
    int H, W;
    long long int N;
    scanf(" %d %d %lld", &H, &W, &N);
 
    vector<int> factors = factorize(N);
    pair<int, int> res;
 
    if (!isPossible(H, W, factors, res))
        printf("Impossible\n");
    
    else 
        printres(H, W, res.first, res.second);
    
 
    return 0;
}