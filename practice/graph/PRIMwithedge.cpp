#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair

int main() {
    int n,e;
    cin>>n>>e;
    int a,b,w;
    vector<pair<int,int>> g[n];
    multimap<int,int>m;
    for(int i=0;i<e;i++)
    {
        
         
        cin>>a>>b>>w;
        g[a].push_back(mp(w,b));
        g[b].pb(mp(w,a));         
    }
    priority_queue <pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> p;
    p.push(mp(mp(0,0),0));
    int tw=0;
    
    vector<int>vis(n,0);
  //  vis[0]=1;
    while(!p.empty())
    {
        int to=p.top().first.second;
        int w =p.top().first.first;
        int from=p.top().second;
        p.pop();
        
        if(vis[to])
            continue;
        vis[to]=1;
        tw+=w;
        m.insert(mp(from,to));
       
       for(auto x: g[to])
       {
           if(!vis[x.second])
           {
               p.push(mp(mp(x.first,x.second),to));
           }
       }
    }
    cout<<tw<<endl;
    for(auto x: m)
    {
        cout<<x.first<<" -> "<<x.second<<endl;
    }
}