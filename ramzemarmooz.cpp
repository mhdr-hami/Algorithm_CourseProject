#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define forn(i, n) for(ll i = 0; i < n; i++)
#define watch(x) cout << #x << " : " << x << endl;
const ll mod = 1e7 + 7;
class Node
{
public:
    char c;
    ll frequency;
    vector<Node> child;
};


struct compareNode
{
    bool operator()(Node x, Node y)
    {
        if(x.frequency == y.frequency)
        {
            if(x.c == '-' && y.c != '-')
            {
                return true;
            }
            if(x.c != '-' && y.c == '-')
            {
                return false;
            }
        }
        return x.frequency > y.frequency;
    }
};

bool compareNodeSort(Node x, Node y)
{
    return x.frequency < y.frequency;
}



Node mergeNode(vector<Node> l)
{
//    sort(l.begin(), l.end(), compareNodeSort);
    Node temp;
    temp.frequency = 0;
    temp.c = '-';
//    cout << "merging :\n";
    forn(i, l.size())
    {
//        cout << l[i].c << " ";
        temp.frequency += l[i].frequency;
        temp.child.push_back(l[i]);
    }
//    cout << endl;
    return temp;
}

Node tree_generate(ll n, string key, string text)
{
    priority_queue<Node, vector<Node>, compareNode> pq;
    vector<ll> freq(key.size());
    for(ll i = 0; i < key.size(); i++)
    {
        Node temp;
        temp.c = key[i];
        temp.frequency = 0;
        for(ll j = 0; j < text.size(); j++)
        {
            temp.frequency += ((text[j] == key[i])? 1 : 0);
        }
        if(temp.frequency > 0)
        {
            pq.push(temp);
        }
    }
    ll N = pq.size();
    while(N > 1)
    {
        vector<Node> l;
        for(ll i = 0; i < n && N > 0; i++)
        {
            l.push_back(pq.top());
//            watch(pq.top().c);
//            watch(pq.top().frequency);
//            cout << endl;
            pq.pop();
            N--;
        }
        Node d = mergeNode(l);
        pq.push(d);
        N++;
    }
    return pq.top();
}
string charFindAns;
void charFind(Node root, char x, string ans, ll n)
{
    if(root.c == x)
    {
        charFindAns = ans;
        return;
    }
    for(ll i = 0; i < root.child.size(); i++)
    {
        charFind(root.child[i], x, ans + "" + to_string(i), n);
    }
}
string waste;
int main ()
{
    string key = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    ll n, m;
    string text;
    cin >> n >> m;
    cin >> text;
    Node root = tree_generate(n, key, text);
    forn(i, key.size())
    {
        charFind(root, key[i], "", n);
    }
    forn(i, m)
    {
        string s;
        cin >> s;
        forn(j, s.size())
        {
            charFind(root, s[j], "", n);
//            cout << s[j] << " : " << charFindAns << '\n';
            cout << charFindAns;
        }
        cout << endl;
    }
    return 0;
}
