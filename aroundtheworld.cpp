#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define watch(x) cout<<(#x)<<" is "<<(x)<<endl;

typedef vector<ll> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef map<int, int> mii;

bool flag = false;

bool promissing (int node, int ** graph, int path[], int n)
{
    if(node == n-1 && !graph[path[n-1]][path[0]])
        return false;
    if(node > 0 && !graph[path[node-1]][path[node]])
        return false;
    for(int i=0; i<node; i++)
        if(path[i] == path[node])
            return false;
    return true;

}


void hamiltonian (int node, int n, int path[],int ** graph)
{
    if(promissing(node,graph,path, n))
    {
        if(node==n-1)
        {
            flag = true;
            return;
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                path[node + 1] = i;
                hamiltonian(node+1 , n, path,graph);
            }
        }
    }
}


int main()
{
    int t,n;
    cin>>t>>n;
    vi vec;
    while (t--)
    {
        int ** graph = new int * [n];
        for(int i=0; i<n; i++)
            graph[i] = new int [n];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>graph[i][j];
        int * path = new int [n];
        path[0] = 0;
        hamiltonian(0,n,path,graph);
        if(flag)
            vec.push_back(1);
        else
            vec.push_back(0);
        flag = false;

    }
    for(int i=0; i<vec.size(); i++)
    {
        if(vec[i])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }




    return 0;
}
