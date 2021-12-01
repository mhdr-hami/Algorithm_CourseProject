#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define forn(i, n) for(ll i = 0; i < n; i++)
#define watch(x) cout << #x << " : " << x << endl;
const ll mod = 1e7 + 7;

string waste;

class Experience
{
public:
    vector<ll> details;
    char result;
    ld score;
};
ld J(Experience ex, vector<ll> test)
{
    ld n_intersection = 0, n_union = 0;
    for(ll i = 0; i < test.size(); i++)
    {
        if(count(ex.details.begin(), ex.details.end(), test[i]) != 0)
        {
            n_intersection++;
        }
    }
    n_union = test.size() + ex.details.size() - n_intersection;
    return 1 - (ld)n_intersection / n_union;
}
bool compareExp(Experience a, Experience b)
{
    return a.score < b.score;
}
void fillAndSort(vector<Experience> &v, vector<ll> test)
{
    forn(i, v.size())
    {
        v[i].score = J(v[i], test);
    }
    sort(v.begin(), v.end(), compareExp);
}
char predict(vector<Experience> &v, vector<ll> test, ll k)
{
    fillAndSort(v, test);
    ll O = 0, X = 0;
    forn(i, k)
    {
        if(v[i].result == 'X')
        {
            X++;
        }
        else
        {
            O++;
        }
    }
    return (X > O)? 'X' : 'O';
}
int main ()
{
    ll D, k, N;
    cin >> D >> k >> N;
    Experience sample;
    vector<Experience> history(D, sample);
    forn(i, D)
    {
        forn(j, N)
        {
            ll x;
            cin >> x;
            history[i].details.push_back(x);
        }
    }
    forn(i, D)
    {
        cin >> history[i].result;
    }
    ll T;
    cin >> T;
    while(T--)
    {
        vector<ll> s;
        forn(i, N)
        {
            ll x;
            cin >> x;
            s.push_back(x);
        }
        cout << predict(history, s, k) << " ";
    }
    return 0;
}
