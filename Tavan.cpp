#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(ll i = 0; i < n; i++)
#define watch(x) cout << #x << " : " << x << endl;
const ll mod = 1e9 + 7;
string waste;
class car
{
public:
    string name;
    ll price;
    ll power;
};

int main ()
{
    ll n, B;
    cin >> n >> B;
    car* a = new car[n];
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i].name >> a[i].price >> a[i].power;
    }
    ll dp[n + 1][B + 1];
    int p[n + 1][B + 1];
    forn(i, n + 1)
            forn(j, B + 1)
                p[i][j] = 0;

    forn(i, n + 1)
    {
        dp[i][0] = 0;
    }
    forn(i, B + 1)
    {
        dp[0][i] = 0;
    }
    for(ll i = 1; i < n + 1; i++)
    {
        for(ll j = 1; j < B + 1; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if(a[i - 1].price <= j)
            {
                if(dp[i][j] < dp[i - 1][j - a[i - 1].price] + a[i - 1].power)
                {
                    dp[i][j] = dp[i - 1][j - a[i - 1].price] + a[i - 1].power;
                    p[i][j] = 1;
                }
            }
            else
            {
                p[i][j] = 0;
            }
        }
    }

    cout << dp[n][B] << endl;

    ll i = n, j = B;
    vector<pair<ll, string>> usedOnes;
    while(i && j)
    {
        if(p[i][j] == 1)
        {
            usedOnes.push_back({a[i - 1].power, a[i - 1].name});
            j -= (a[i - 1].price);
            i--;
        }
        else
        {
            i--;
        }
    }
    sort(usedOnes.begin(), usedOnes.end());
    for(ll i = usedOnes.size() - 1; i >= 0; i--)
    {
        cout << usedOnes[i].second << " ";
    }
    return 0;
}
