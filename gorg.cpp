#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define watch(x) cout<<(#x)<<" is "<<(x)<<endl;
#define forn(i, n) for (int i = 0; i < int(n); i++)


typedef vector<ll> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef map<int, int> mii;

struct node
{
    int x;
    int y;
    int dist;
};

int mindist (char ** table , vector<pair < int , pair< int, int> > >sheeps,int n,int m)
{
    node source;
    int ans =0;
    source.x = 0;
    source.y = 0;
    source.dist = 0;
    while (sheeps.size())
    {
        for(int sh=0; sh<sheeps.size(); sh++)
        {
            int xdest = sheeps[sh].second.first;
            int ydest = sheeps[sh].second.second;
            bool visited[n][m];
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    if(table[i][j] == '*')
                        visited[i][j] = true;
                    else
                        visited[i][j] = false;
                }
            }
            queue <node> qu;
            qu.push(source);
            visited[source.x][source.y] = true;
            while (!qu.empty())
            {
                node p = qu.front();
                qu.pop();

                //sheep check
                if(p.x == xdest && p.y==ydest)
                {
                    sheeps[sh].first = p.dist;
                    break;
                }

                //bala
                if(p.x - 1>=0 && visited[p.x -1][p.y] == false)
                {
                    node tmp;
                    tmp.x = p.x - 1;
                    tmp.y = p.y;
                    tmp.dist = p.dist +1;
                    visited[tmp.x][tmp.y] = true;
                    qu.push(tmp);
                }

                //pain
                if(p.x + 1< n && visited[p.x +1][p.y] == false)
                {
                    node tmp;
                    tmp.x = p.x + 1;
                    tmp.y = p.y;
                    tmp.dist = p.dist +1;
                    visited[tmp.x][tmp.y] = true;
                    qu.push(tmp);
                }

                //chap
                if(p.y - 1 >= 0 && visited[p.x][p.y -1] == false)
                {
                    node tmp;
                    tmp.x = p.x;
                    tmp.y = p.y -1;
                    tmp.dist = p.dist +1;
                    visited[tmp.x][tmp.y] = true;
                    qu.push(tmp);
                }

                //rast
                if(p.y + 1 <m  && visited[p.x][p.y +1] == false)
                {
                    node tmp;
                    tmp.x = p.x;
                    tmp.y = p.y +1;
                    tmp.dist = p.dist +1;
                    visited[tmp.x][tmp.y] = true;
                    qu.push(tmp);
                }
            }
        }
        sort(sheeps.begin(), sheeps.end());
        ans += sheeps[0].first;
//        cout<<"sheeps: "<<endl;
//        for(auto i : sheeps)
//            cout<<i.first<< " "<< i.second.first<< " "<<i.second.second<<endl;
//        watch(ans);
        source.x = sheeps[0].second.first;
        source.y = sheeps[0].second.second;
        sheeps.erase(sheeps.begin());
//        cout<<"new sheeps: "<<endl;
//        for(auto i : sheeps)
//            cout<<i.first<< " "<< i.second.first<< " "<<i.second.second<<endl;
//        cout<<"-------------------------";
    }
//    cout<<"1111"<<endl;
//    watch(ans);
//    cout<<source.x<<" "<<source.y<<endl;

    int xdest,ydest;
    bool visited[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(table[i][j] == '*')
                visited[i][j] = true;
            else
                visited[i][j] = false;
            if(table[i][j] == 'X')
            {
//                cout<<"chupan"<<endl;
                xdest = i;
                ydest = j;
//                watch(xdest);
            }
        }
    }
    queue <node> qu;
    qu.push(source);
    visited[source.x][source.y] = true;
    while (!qu.empty())
    {
        node p = qu.front();
        qu.pop();
//        watch(p.x);
//        watch(p.y);
//        watch(p.dist);
//        cout<<"----"<<endl;

        //sheep check
        if(p.x == xdest && p.y==ydest)
        {
//            cout<<"found!"<<endl;
            ans += p.dist;
//            watch(ans);
            return ans;
        }

        //bala
        if(p.x - 1>=0 && visited[p.x -1][p.y] == false)
        {
            node tmp;
            tmp.x = p.x - 1;
            tmp.y = p.y;
            tmp.dist = p.dist +1;
            visited[tmp.x][tmp.y] = true;
            qu.push(tmp);
        }

        //pain
        if(p.x + 1< n && visited[p.x +1][p.y] == false)
        {
            node tmp;
            tmp.x = p.x + 1;
            tmp.y = p.y;
            tmp.dist = p.dist +1;
            visited[tmp.x][tmp.y] = true;
            qu.push(tmp);
        }

        //chap
        if(p.y - 1 >= 0 && visited[p.x][p.y -1] == false)
        {
            node tmp;
            tmp.x = p.x;
            tmp.y = p.y -1;
            tmp.dist = p.dist +1;
            visited[tmp.x][tmp.y] = true;
            qu.push(tmp);
        }

        //rast
        if(p.y + 1 <m  && visited[p.x][p.y +1] == false)
        {
            node tmp;
            tmp.x = p.x;
            tmp.y = p.y +1;
            tmp.dist = p.dist +1;
            visited[tmp.x][tmp.y] = true;
            qu.push(tmp);
        }
    }
}


int main()
{
    //    ios_base::sync_with_stdio(false);cout<<fixed;cout<<setprecision(12);

    //* Do Not Rush *//
    int n,m,k;
    cin>>n>>m>>k;
    char ** table  = new char * [n];
    for(int i=0; i<n; i++)
        table[i] = new char [m];

    vector<pair < int , pair< int, int> > >sheeps;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            cin>>table[i][j];
            if(table[i][j] == 'S')
                sheeps.push_back({-1,{i,j}});
        }
    cout<<mindist(table,sheeps,n,m);






    return 0;
}
