#include <bits/stdc++.h>
using namespace std;
struct dsu{
    vector<int>par;
    multimap<int,int>m;
    
    int total=0;
    
    void init(int n)
    {
        par.resize(n);
       
        for(int i=0;i<n;i++)
        {
            par[i]=i;
            
        }
       
    }
    int getsp(int x)
    {
        if(x==par[x])
            return x;
        return par[x]=getsp(par[x]);
    }
    void unite(int w,int x,int y)
    {
        int spx=getsp(x);
        int spy=getsp(y);
        if(spx!=spy)
        {
            par[spx]=spy;
            m.insert(make_pair(x,y));
          //  cout<<w;
            total+=w;
           
        }
       
    }
}g;
int main() {
   
    int n,m;
    cin>>n>>m;
    g.init(m);
    vector<vector<int>>v(m);

    for(int i=0;i<m;i++)
    {
        int a,b;
        int w;
        cin>>a>>b>>w;
        v[i]={w,a,b};
    }
    sort(v.begin(),v.end());
    for(int i=0;i<m;i++)
    {
        int w=v[i][0];
        int a=v[i][1];
        int b=v[i][2];
       // cout<<w<<" "<<a<<" "<<b<<endl;
        g.unite(w,a,b);

    }
    cout<<"prim's wt is "<<g.total<<endl;
    for(auto x:g.m)
    {
        cout<<x.first<<" -> "<<x.second<<endl;
    }
   

}
/*                  INPUT
9 14
0 1 4
0 7 8 
1 2 8
1 7 11 
2 3 7 
2 8 2 
2 5 4 
3 4 9 
3 5 14 
4 5 10 
5 6 2 
6 7 1 
6 8 6
7 8 7
output:37
*/