#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool ispossible(ll * rnk,ll minTime,ll paranthas,ll n)
{  // ll cnt =0;
    
    for(ll i=0;i<n;i++)
    {ll tm=0;
    ll ct=1;
    while(tm+ct*rnk[i]<=minTime and paranthas>0){
      tm+=ct*rnk[i];
      paranthas--;
      ct++;
    }
    if(paranthas==0)return true;
  }
  return (paranthas==0);
}
ll ans;
ll parantha(ll *a,ll n,ll p,ll l,ll h)
{
    
    while(l<=h)
	{
		ll  m=(l+h)/2;
		if(ispossible(a,m,p,n))
   		{
   			ans=m;
        	h=m-1;
    	}
    	else
    		l=m+1;
		
	}
    return ans;
    
}

int main() {
    ll p;
    ll n;
    cin>>p>>n;
    ll a[55];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll lo=0;
    ll high=1e18;
    sort(a,a+n);
   
   cout<<parantha(a,n,p,lo,high);
    return 0;
}

