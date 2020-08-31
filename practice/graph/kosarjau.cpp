#include<bits/stdc++.h>
#include<vector>
#define ff              first
#define ss              second

#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define frr(a,b)        for(int i=a;i<b;i++)
#define all(a)          a.begin(),a.end()
using namespace std;


 const int na=1000;
 vector<int>* g=new vector<int>[na];//graph
vector<int>* h=new vector<int>[na];  // reverse graph
int vis[na];            //visited
int cmp[na];            //in which component
vi inc[na];             //elememts in component
vi od;                  //topo order
void dfs(int src)
{
    vis[src]=true;
   
    for(auto x:g[src])
    {
        if(!vis[x])
        {
           dfs(x);
        }
    }
   od.push_back(src);           //topo
}
void rdfs(int src,int col)
{
    cmp[src]=col;
    inc[col].pb(src);
    vis[src]=true;
   
    for(auto x:h[src])
    {
        if(!vis[x])
        {
           rdfs(x,col);
        }
    }
  // od.push_front(src);
}

int32_t main()
{


    int n,v;
    cin>>n>>v;
  //  map<int,list<int>> g; 
   
    frr(0,v)
    {
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
        h[b].pb(a);

    }

    frr(0,v)
    {
        if(!vis[i])
            dfs(i);
    }
    memset(vis,0,sizeof(vis));
    int col =1;
   // for(int i=n-1;i>=0;i--)
    frr(0,n)
    {
        if(!vis[od[i]])
        {
            rdfs(od[i],col);
            col++;
        }
       
    }
    frr(0,n)
        cout<<od[i]<<" ";
    cout<<endl;
    frr(0,n)
        cout<<i<<" -> "<<cmp[i]<<endl;
    }