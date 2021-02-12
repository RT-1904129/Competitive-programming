#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
 ll n,k,x;
 cin>>n>>k;
 deque<ll> dq;
 for(ll i=0;i<n;i++){
      cin>>x;
      dq.push_back(x);
 }                                  //Minimize Difference After Removing K Elements
 deque<ll>diff;
 for(ll i=0;i<n-1;i++){
    diff.push_back(dq[i+1]-dq[i]);
 }
 ll max_diff=0,count=0;
 for(ll i=0;i<n-1;i++){
    if(diff[i]>max_diff) {max_diff=diff[i];count=i+1;}
 }
 cout<<count<<"\n";
 if(count==k){
            max_diff=0;
            for(ll i=count;i<n-1;i++){
            if(diff[i]>max_diff) max_diff=diff[i];
         }
         cout<<max_diff;
         return 0;
 }
 else if((n-count)==k) {
     max_diff=0;
            for(ll i=0;i<count-1;i++){
            if(diff[i]>max_diff) max_diff=diff[i];
         }
         cout<<max_diff;
         return 0;
 }
 else{
         while(k--){
          auto itr_front=dq.begin(),itr_back=dq.end();
          ll front_diff=*(itr_front+1)-*itr_front;
          ll back_diff=*(itr_back-1)-*(itr_back-2);
          if(front_diff>back_diff) dq.pop_front();
          else dq.pop_back();
         }
         ll min_diff=-1;
         for(ll i=dq.size()-1;i>=1;i--){
           if(dq[i]-dq[i-1]>min_diff) min_diff=dq[i]-dq[i-1];
         }
         cout<<min_diff;
         return 0;}
}