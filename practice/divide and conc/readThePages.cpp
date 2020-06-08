#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool ispossible(ll * a,ll m,ll n,ll p)
{  ll i=0;
    ll tm;
  
    for(ll f=0;f<p;f++)
    {
        tm=0;
        while(tm+a[i]<=m&&i<n)
        {
            tm+=a[i];
        
            i++;
        }
        if(i==n){
   
            return true;}
    }
    return (i==n);    		
}
ll ans;
ll books(ll *a,ll n,ll l,ll h,ll p)
{
 if(p==1)
    return h;
if(l==h)
    return h;
    while(l<=h)
	{
		ll  m=(l+h)/2;
		if(ispossible(a,m,n,p))
   		{
       
   			ans=m;
        	h=m-1;
    	}
    	else{
      
        
    		l=m+1;
        }
	}
  
    return ans;
    
}

int main() {
    ll k;
    ll n;
    cin>>n>>k;
    ll a[100000];
    ll s=0;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }

  //  sort(a,a+n);
   

   
    
  
   
   cout<<books(a,n,a[0],s,k);
    return 0;
}

