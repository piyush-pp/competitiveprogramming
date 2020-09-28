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
int32_t main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

    int n,v;
    cin>>n>>v;
  //  map<int,list<int>> g; 
    vector<int>* g=new vi[n];
    frr(0,v)
    {
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);

    }
    int ans=n;
    for(int src=0;src<n;src++)
    {
        vi dis(n,INT_MAX);
        dis[src]=0;
        list<int> l;
        l.pb(src);
        while(!l.empty())
        {
            int t=l.front();
            l.pop_front();
           // auto z=g[t];
             for(auto x:g[t])
            {
                if(dis[x]==INT_MAX)
                {
                    l.pb(x);
                    dis[x]=dis[t]+1;
                }
                else if(dis[x]>=dis[t])
                {
                    ans=min(ans,dis[x]+dis[t]+1);
                }
            }
        }

    }
    if(ans==n)
        cout<<"no";
    else
        cout<<ans;
}