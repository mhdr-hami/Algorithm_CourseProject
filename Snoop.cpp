#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define watch(x) cout<<(#x)<<" is "<<(x)<<endl;
#define forn(i, n) for (int i = 0; i < int(n); i++)


typedef vector<ll> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef map<int, int> mii;

//bool intable (int i, int j, int n, int m)
//{
//    if(i>=0 && j>=0 && i<n && j<m)
//        return true;
//    return false;
//}
ll bin (ll n, ll k)
{
    ll dp[n+1][k+1];
    for(ll i=0; i<=n; i++)
    {
        for(ll j=0; j<=min(i,k); j++)
        {
            if (j==0 || i==j)
                dp[i][j] = 1;
            else
            {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                dp[i][j] = dp[i][j]%10000001;
            }
        }
    }
    return dp[n][k];
}


int main()
{
    //    ios_base::sync_with_stdio(false);cout<<fixed;cout<<setprecision(12);

    //* Do Not Rush *//
//    int n,m,k;
//    vector < pair<int,int> > V;
//    vector<vector<pair<int,int> > > adj(v,V);
//    char ** table = new char * [n];
//    for(int i=0; i<n; i++)
//        table[i] = new char[m];
//    for(int i=0; i<n; i++)
//        for(int j=0; j<m; j++)
//            cin>>table[i][j];
//    for(int i=0; i<n; i++)
//        for(int j=0; j<m; j++)
//        {
//            if(intable(i-1,j-1,n,m) && table[i][j]!='*' && table[i-1][j-1]!='*')

//        }
    ll n,k;
    cin>>n>>k;
    ll kk = k;
    kk+=n-1;
    for(ll i=0; i<n; i++)
    {
        ll x;
        cin>>x;
        kk -=x;
    }
    n--;
    kk%=10000001;
    cout<<bin(kk,n)%10000001<<endl;






    return 0;
}
