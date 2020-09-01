
///https://ide.codingblocks.com/s/240346

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll partition(ll * a,int s,int e)
{
   
	ll i =s-1;
    ll j=s;
    ll pivot=a[e];
    for(;j<e;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(a[i],a[j]);

        }
    }
    swap(a[i+1],a[e]);
    return i+1;
    

}
void sort(ll *arr,ll s,ll e)
{
	if(s>=e)
		return ;
	ll p=partition(arr,s,e);
    sort(arr,s,p-1);
    sort(arr,p+1,e);
	
	return ;
}
void shuffle(ll *a,ll s,ll e)
{
    ll j;
    srand(time(NULL));
    for(ll i=e;i>0;i--)
    {
        j=rand()%(i+1);
        swap(a[i],a[j]);
    }
    return;
}
int main() {
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
		ll n;
		cin>>n;
		ll arr[1000000];
        ll flag=0;
		for(ll i=0;i<n;i++)
        {
			cin>>arr[i];
           
        }
       
        shuffle(arr,0,n-1);
        sort(arr,0,n-1);
        for(ll i=0;i<n;i++)
        {
			cout<<arr[i]<<" ";
           
        }
       
	
	return 0;
}
