#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define watch(x) cout<<(#x)<<" is "<<(x)<<endl;
#define forn(i, n) for (int i = 0; i < int(n); i++)


typedef vector<ll> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef map<int, int> mii;


void dfs (int node, vector<int> graph[], int dp[], bool visited[])
{
    visited[node] = true;
    for(int i=0; i<graph[node].size(); i++)
    {
        if(!visited[graph[node][i]])
            dfs(graph[node][i],graph, dp,visited);

        dp[node] = max(dp[node] , 1 + dp[graph[node][i]]);
    }
}
void dfs_traversal (int node, vector<int> graph[], int dp[], int v)
{
    vector <bool> visited(v+1,false);
    stack <int> sk;
    sk.push(node);
    while (!sk.empty())
    {
        int s = sk.top();
        sk.pop();
        if(!visited[s])
        {
            dp[node]++;
            visited[s] = true;
        }
        for(int i=graph[s].size()-1 ; i>=0; i--)
            if(!visited[graph[s][i]])
                sk.push(graph[s][i]);
    }
    dp[node]--;

}

int findlongestPath(vector<int> graph[] , int n)
{
    int dp[n+1];
    for(int i=0; i<=n; i++)
        dp[i] = 0 ;

    for(int i=1; i<=n; i++)
        dfs_traversal(i,graph,dp,n);
    int mx=dp[1],mx_index=1;
    for(int i=2; i<=n; i++)
        if(dp[i] > mx)
        {
            mx = dp[i];
            mx_index= i;
        }
    return mx_index;

}


int main()
{
    //    ios_base::sync_with_stdio(false);cout<<fixed;cout<<setprecision(12);

    //* Do Not Rush *//
    int n;
    cin>>n;
    vi ans;
    while (n)
    {
        vector<int> graph[n+1];
        for(int i=0; i<n; i++)
        {
            int cnt;
            cin>>cnt;
            for(int j=0; j<cnt; j++)
            {
                int x;
                cin>>x;
                graph[i+1].push_back(x);
            }
        }

        ans.push_back(findlongestPath(graph,n));
        cin>>n;
    }
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<endl;



    return 0;
}
