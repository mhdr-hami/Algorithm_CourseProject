#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(ll i = 0; i < n; i++)
#define watch(x) cout << #x << " : " << x << endl;
const ll mod = 1e9 + 7;
string waste;

int main ()
{
    ll n;
    cin >> n;
    ll * arr = new ll[n];
    string * s = new string[n];
    forn(i, n)
    {
        cin >> s[i];
        ll index = -1;
        for(ll j = 0; j < n; j++)
        {
            if(s[i][j] == '1')
            {
                index = j;
            }
        }
        arr[i] = index;
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++)
    {
        if(arr[i] > i)
        {
            ll index = i;
            for(ll j = i + 1; j < n; j++)
            {
                if(arr[j] <= i)
                {
                    index = j;
                    break;
                }
            }
            for(ll j = index; j > i; j--)
            {
                swap(arr[j], arr[j - 1]);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
