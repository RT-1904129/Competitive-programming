#include <iostream>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long int rt;

void K_diff_Pairs_in_an_Array(vector<rt>&array,rt &k){
    rt sum1=0,sum2=0,count=0;
    unordered_map<rt,rt>arr;
    for(rt i=0;i<array.size();++i) arr[array[i]]++;
    for(auto itr=arr.begin();itr!=arr.end();++itr){
        if((!k && itr->second>1) ||(k && arr.count(itr->first + k))) count++;
    
    }
    cout<<count;
}


int main(){
    rt t,a,k;
    ios::sync_with_stdio(false);
    vector<rt>array;
    cin>>t>>k;
    for (rt i = 0; i < t; i++){
        cin>>a;
        array.push_back(a);
    }
    K_diff_Pairs_in_an_Array(array,k);
}