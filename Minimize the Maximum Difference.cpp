#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;
typedef long long int rt;
rt Minimize_the_Maximum_Difference(vector<rt>&arr,rt & k){
    rt n=arr.size();
    if(n==1) return 0;
    sort(arr.begin(),arr.end());
    rt ans=arr[n-1]-arr[0];
    rt minimum=arr[0]+k;
    rt maximum=arr[n-1]-k;
    if (minimum > maximum)
        swap(minimum, maximum);
    for(rt i=1;i<n-1;++i){
        rt add =arr[i]+k;
        rt sub=arr[i]-k;
        if(sub>=minimum || add<= maximum) continue;
        if(maximum-sub<=add-minimum) 
            minimum=sub;
        else maximum=add;
    }
    return min(maximum-minimum,ans);
}

int main(){
    rt t,h,count,a;
    cin>>t>>h;
    vector<rt>arr;
    for(int i=0;i<t;++i){
        cin>>a;
        arr.push_back(a);
    }
    cout<<Minimize_the_Maximum_Difference(arr,h);
}