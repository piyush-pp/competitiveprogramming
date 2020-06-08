
///https://ide.codingblocks.com/s/240963

#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool ispossible(ll * a,ll m,ll c,ll n)
{   ll cnt =1;
    ll temp=a[0];
    for(ll i=1;i<n;i++)
    {
        if(a[i]-temp>=m)
        {
            temp=a[i];
            cnt++;
            if(cnt>=c)
                return true;
            
        }

    }
    return false;
}
ll ans;
ll aggr(ll *a,ll s,ll e,ll c,ll n)
{
    
    if(s>=e)
        return 0;
    if(c==2)
    {
        return(e-s);
    }
    ll m=(s+e)/2;
    if(ispossible(a,m,c,n))
    {
        
        ans=m;
        aggr(a,m+1,e,c,n);
    }
    else
    {
        aggr(a,s,m-1,c,n);
    }
    return ans;
}

int main() {
    ll n;
    ll c;
    cin>>n>>c;
    ll a[100000];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    sort(a,a+n);
   
   cout<<aggr(a,a[0],a[n-1],c,n);
    return 0;





}

