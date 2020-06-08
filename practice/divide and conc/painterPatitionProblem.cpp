
https://ide.codingblocks.com/s/241525

#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool ispossible(ll * a,ll m,ll n,ll p)
{  ll i=0;
    ll tm;
  //  cout<<m<<";"<<n<<"    ";
    for(ll f=0;f<p;f++)
    {
        tm=0;
        while(tm+a[i]<=m&&i<n)
        {
            tm+=a[i];
         //   cout<<tm<<","<<i<<" ";
            i++;
        }
        if(i==n){
    //        cout<<"run"<<i;
            return true;}
    }
    return (i==n);    		
}
ll ans;
ll painter(ll *a,ll n,ll l,ll h,ll p)
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
        //     cout<<" 1"<<endl;
   			ans=m;
        	h=m-1;
    	}
    	else{
      //    cout<<" 0"<<endl;
        
    		l=m+1;
        }
	}
   // cout<<endl;
    return ans;
    
}

int main() {
    ll k;
    ll n;
    cin>>k>>n;
    ll a[55];
    ll s=0;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }

  //  sort(a,a+n);
   

    ll l=*max_element(a,a+n);
    
  
   
   cout<<painter(a,n,l,s,k);
    return 0;
}

