#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       set<ll> s;
       ll a;

       for(int i=0;i<n;i++)
       {
           cin>>a;
           if(a>0)
             s.insert(a);
       }
         cout<<s.size()<<endl;
         s.clear();
   }
  

}
