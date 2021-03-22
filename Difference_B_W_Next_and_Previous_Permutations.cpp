#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int rt;
rt Difference_B_W_Next_and_Previous_Permutations(rt x){
    vector<rt>arr;
    rt a=0,b=0;
    while(x){
        arr.push_back(x%10);
        x/=10;
    }
    vector<rt>arr1(arr.size());
    reverse(arr.begin(),arr.end());
    copy(arr.begin(),arr.end(),arr1.begin());
    next_permutation(arr.begin(),arr.end());
    prev_permutation(arr1.begin(),arr1.end());
    for(rt i=0;i<arr.size();++i) a=a*10+arr[i];
    for(rt i=0;i<arr.size();++i) b=b*10+arr1[i];
    return(a-b);
}

int main(){
    ios::sync_with_stdio(false);
    rt a,b;
    cin>>a;
    vector<rt>arr;
    for(rt i=0;i<a;++i){
        cin>>b;
        arr.push_back(b);
    }
    for(rt i=0;i<a;++i)
        arr[i]=Difference_B_W_Next_and_Previous_Permutations(arr[i]);
    cout<<*max_element(arr.begin(),arr.end());
    return 0;
}