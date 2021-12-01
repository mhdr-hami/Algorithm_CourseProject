#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define watch(x) cout<<(#x)<<" is "<<(x)<<endl;
#define forn(i, n) for (int i = 0; i < int(n); i++)


typedef vector<ll> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef map<int, int> mii;
const int MX=3e2+200,maxb=35,D=1e9+7;
#define int long long
#define ll long long
#define ld long double
#define pb push_back
#define F first
#define S second

int n,m;
bool mark[MX];
vector<int> gr[MX], comp[MX];
int pv[MX][MX][MX];
int p[MX][MX];
double f[MX];
int dis[MX];

void dfs(int v, int co){
    mark[v]=1;
    comp[co].pb(v);
    for(auto u: gr[v]){
        if(!mark[u]) dfs(u, co);
    }
}

void bfs(int root){
    vector<int> vec;
    mark[root]=1;
    dis[root]=0;
    vec.pb(root);
    p[root][root]=1;
    int st=0, ed=1;
    while(st<ed){
        int v=vec[st++];
        for(auto u: gr[v]){
            if(!mark[u]){
                dis[u] = dis[v]+1;
                vec.pb(u);
                mark[u]=1;
                ed++;
            }
            if(dis[u]==dis[v]-1){
                p[root][v]+=p[root][u];
                for(int i=0; i<n; i++){
                    pv[i][root][v]+=pv[i][root][u];
                }
            }
        }
        pv[v][root][v]=p[root][v];
        pv[root][root][v]=p[root][v];
    }
}
bool big(int v, int u){
    return f[v]>f[u];
}


//void dfs_findComponent (int node, vector<int> graph[], bool visited[], int v,
//                        vector<vector<vector<int> > > & Components)
//{
//    stack <int> sk;
//    vector <int> V;
//    vector<vector< int > > comp(v,V);
//    sk.push(node);

//    while (!sk.empty())
//    {
//        int s = sk.top();
//        sk.pop();
//        if(!visited[s])
//        {
//            visited[s] = true;

//        }
//        for(int i=graph[s].size()-1 ; i>=0; i--)
//            if(!visited[graph[s][i]])
//            {
//                sk.push(graph[s][i]);
//                comp[s].push_back(graph[s][i]);
//                comp[graph[s][i]].push_back(s);
//            }
//    }

//    Components.push_back(comp);
//}

//void BFS(vector< vector<int> > adj, int src, int n, int ** ptable)
//{
//    bool visit[n];
//    int dist[n], paths[n];
//    for (int i = 0; i < n; i++)
//    {
//        dist[i] = INT_MAX;
//        paths[i] = 0;
//        visit[i] = false;
//    }
//    dist[src] = 0;
//    paths[src] = 1;

//    queue <int> q;
//    q.push(src);
//    visit[src] = true;
//    while (!q.empty())
//    {
//        int curr = q.front();
//        q.pop();

//        // For all neighbors of current vertex do:
//        for (auto x : adj[curr])
//        {
//            // if the current vertex is not yet
//            // visited, then push it to the queue.
//            if (visit[x] == false)
//            {
//                q.push(x);
//                visit[x] = true;
//            }

//            // check if there is a better path.
//            if (dist[x] > dist[curr] + 1)
//            {
//                dist[x] = dist[curr] + 1;
//                paths[x] = paths[curr];
//            }

//            // additional shortest paths found
//            else if (dist[x] == dist[curr] + 1)
//                paths[x] += paths[curr];
//        }
//    }
//        cout<<"src : "<<src<<" : ";

//    for(int i=0; i<n; i++)
//    {
//                cout<<paths[i]<<" ";
//        ptable[src][i] = paths[i];
//    }
//        cout<<endl<<endl;
//}



int32_t main()
{
//    int v,e;
//    cin>>v>>e;
//    vector<int> graph[v];
//    bool visited[v];
//    vector<vector<vector<int> > >Components;
//    for(int i=0; i<e; i++)
//    {
//        int src,des;
//        cin>>src>>des;
//        graph[src].push_back(des);
//        graph[des].push_back(src);
//    }
//    for(int i=0; i<v; i++)
//        visited[i] = false;

//    for(int i=0; i<v; i++)
//        if(!visited[i])
//            dfs_findComponent(i,graph,visited,v,Components);

//            cout<<Components.size()<<endl;
//            for(int i=0; i<Components.size(); i++)
//            {
//                cout<<i+1<<" th compo: "<<endl;
//                for(int j=0; j<Components[i].size(); j++)
//                {
//                    cout << j<< " : ";
//                    for(int k=0; k<Components[i][j].size(); k++)
//                        cout<<Components[i][j][k]<<" , ";
//                    cout<<endl;
//                }
//                cout<<"---------------"<<endl<<endl;
//            }
//    vi ans;
//    for(int i=0; i<Components.size(); i++)
//    {
//        int ** ptable = new int * [v];
//        for(int w=0; w<v; w++)
//            ptable[w] = new int [v];

//        for(int k=0; k<v; k++)
//            for(int j=0; j<v; j++)
//                ptable[k][j] = INT_MAX;

//        for(int k=0; k<v; k++)
//        {
//            if(Components[i][k].size() != 0)
//            {
//                BFS(Components[i],k,v,ptable);
//            }
//        }
//                for(int ww=0; ww<v; ww++)
//                {
//                    if(Components[i][ww].size() != 0)
//                    {
//                        for(int ee=0; ee<v; ee++)
//                        {
//                            if(ptable[ww][ee] == INT_MAX)
//                                cout<<"e"<<" ";
//                            else
//                                cout<<ptable[ww][ee]<<" ";
//                        }
//                        cout<<endl;
//                    }
//                }
//        long double maxffound=0,max_id=-1;
//        for(int k=0; k<v; k++)
//        {
//            if(Components[i][k].size() != 0)
//            {
//                watch(k);
//                long double theF=0;
//                for(int s=0; s<v; s++)
//                {
//                    if(Components[i][s].size() != 0 && s!=k)
//                    {
//                        for(int t=0; t<v; t++)
//                        {
//                            if(Components[i][t].size() != 0 && t!=k)
//                            {
//                                theF = theF + (((long double)(ptable[s][k]) * (long double)(ptable[k][t]))
//                                        / (long double)(ptable[s][t]));
//                            }
//                        }
//                    }
//                }
//                if(theF > maxffound)
//                {
//                    maxffound = theF;
//                    max_id = k;
//                }
//                watch(theF);
//                watch(k);
//            }
//        }
//        ans.push_back(max_id);
//    }
//    sort(ans.begin(), ans.end());
//    for(auto i : ans)
//        cout<<i<<" ";
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int f,s;
        cin>>f>>s;
        gr[f].pb(s);
        gr[s].pb(f);
    }
    int cnt =0;
    for(int i=0; i<n; i++){
        if(!mark[i]){
            dfs(i, cnt++);
        }
    }
    for(int i=0; i<n; i++){
        fill(mark, mark+n, 0);
        fill(dis, dis+n, -1);
        bfs(i);
    }
    vector<int> ans;
    for(int i=0; i<cnt; i++){
        for(auto v: comp[i]){
            for(auto x: comp[i]){
                for(auto y: comp[i]){
                    if(x!=v && y!=v && x>y){
                        f[v]+=1.0*pv[v][x][y]/p[x][y];
                    }
                }
            }
        }
        sort(comp[i].begin(), comp[i].end(), big);
     //   for(auto v: comp[i]) cout<<v<<':'<<f[v]<<' ';
      //  cout<<endl;
        ans.pb(comp[i][0]);
    }
    sort(ans.begin(), ans.end());
    for(auto v: ans){
        cout<<v<<' ';
    }


    return 0;
}
