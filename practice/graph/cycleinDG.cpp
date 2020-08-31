#include<bits/stdc++.h>
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define frr(a,b)        for(int i=a;i<b;i++)
#define all(a)          a.begin(),a.end()
using namespace std;

bool dfs(int src,bool *vis,bool*stk,vi *g)
{
    vis[src]=true;
    stk[src]=true;
    for(auto x:g[src])
    {
        if(stk[x]==true)
            return true;
        if(!vis[x])
        {
            bool cy=dfs(x,vis,stk,g);
            if(cy)
                return true;

        }
    }
    stk[src]=false;
    return false;
}


int32_t main()
{


    int n,v;
    cin>>n>>v;
  //  map<int,list<int>> g; 
    vector<int>* g=new vi[n];
    frr(0,v)
    {
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
     //   g[b].pb(a);

    }

    bool *vis=new bool[n];
     bool *stk=new bool[n];
    bool p=dfs(0,vis,stk,g);
    if(p)
        cout<<"yes";
        else
            cout<<"no";
}