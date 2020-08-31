#include <bits/stdc++.h>
using namespace std;
struct dsu{
    vector<int>par;
    vector<int>sz;
    int total;
    void init(int n)
    {
        par.resize(n);
       
        for(int i=0;i<n;i++)
        {
            par[i]=i;
            
        }
        total=n;
    }
    int getsp(int x)
    {
        if(x==par[x])
            return x;
        return par[x]=getsp(par[x]);
    }
    void unite(int x,int y)
    {
        int spx=getsp(x);
        int spy=getsp(y);
        if(spx!=spy)
        {
            par[spx]=spy;
            total--;
           
        }
        else
            cout<<"this edge will make cyle"<<endl;
    }
}g;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n,m;
    cin>>n>>m;
    g.init(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        g.unite(a,b);
    }
   

}
