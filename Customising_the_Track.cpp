#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
typedef unsigned long long int ulli;
typedef long long int lli;
typedef long int li;

void  Customising_the_Track(vector<lli> & arr,lli n){
    lli start=0,mid,sum=0,old;
    for(lli i=0;i<n;++i){
        sum+=arr[i];
    }
    old=sum/n;
    if(sum%n==0){
        sum=0;
        // for(start =0;start<n;++start){
        //   arr[start]=old;
        // }
    }
    else{
        mid=sum%n;
        sum=(n-mid)*mid;
        // for(start =0;start<n;++start){
        //   if(mid>0) arr[start]=old+1;
        //   else arr[start]=old;
        //   mid--;
        // }
    }
    // sum=0;
    // for(lli i=0;i<n;++i){
    //     // cout<<arr[i]<<" ";
    //     for(lli j=i+1;j<n;++j){
    //         sum+=abs(arr[j]-arr[i]);
    //      }
    // }
    cout<<sum<<"\n";
}




int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    lli n,m,t;
    cin>>t;
    while(t--){
        cin>>n;
       vector<lli>arr(n);
       for(lli i=0;i<n;++i) cin>>arr[i];
       Customising_the_Track(arr,n);
    }
    
    return 0;
}