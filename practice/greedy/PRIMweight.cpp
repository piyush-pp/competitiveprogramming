#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair

int main() {
    int n,m;
    cin>>n>>m;
    int a,b,w;
    vector<pair<int,int>> g[n];
    for(int i=0;i<m;i++)
    {
        
         
        cin>>a>>b>>w;
        g[a].push_back(mp(w,b));
        g[b].pb(mp(w,a));         
    }
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
    p.push(mp(0,0));
    int tw=0;
    vector<int> vis(n,0);
    while(!p.empty())
    {
        int w=p.top().first;
        int to=p.top().second;
        p.pop();
        if(vis[to])
            continue;

        tw+=w;
        vis[to]=1;
        
        for(auto x:g[to])
        {
            if(!vis[x.second])
            {
                p.push(mp(x.first,x.second));
            }
        }
    }
    cout<<tw;
}
