#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define CONFIG ios_base::sync_with_stdio(false);cout<<fixed;cout<<setprecision(10);

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef map<int, int> mii;

ll findmin (ll dist[] , bool mstSet [], ll v)
{
    ll mn = LONG_LONG_MAX, mn_index;
    for(ll i=0; i<v; i++)
    {
        if(!mstSet[i] && dist[i]< mn)
        {
            mn = dist[i], mn_index = i;
        }
    }
    return mn_index;

}

ll findAns (ll prnt[] , ll ** graph, ll v)
{
    ll ans =0;
    for(ll i=1; i<v; i++)
        ans+=graph[i][prnt[i]];
    return ans;
}

void primMST(ll **graph,ll v)
{    
    ll prnt[v];
    bool mstSet[v];
    ll dist[v];

    for (ll i = 0; i < v; i++)
        dist[i] = LONG_LONG_MAX, mstSet[i] = false;

    dist[0] = 0;
    prnt[0] = -1; // First node is always root of MST

    for (ll i = 0; i < v - 1; i++)
    {
        ll u = findmin(dist, mstSet, v);
        mstSet[u] = true;

        for (ll j = 0; j < v; j++)
            if (graph[u][j] && mstSet[j] == false && graph[u][j] < dist[j])
                prnt[j] = u, dist[j] = graph[u][j];
    }

    cout<< findAns(prnt, graph, v);
}

int main()
{
    ll n,m;
    cin>>n>>m;

    ll **graph = new ll * [n] ;
    for(ll i=0; i<n;i++)
        graph[i] = new long long [n];
    for(ll i=0; i<n;i++)
        for(ll j=0; j<n; j++)
            graph[i][j] = 0;
    for(ll i=0; i<m; i++)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        graph[x][y] = z;
        graph[y][x] = z;
    }
    primMST(graph,n);



    return 0;
}
