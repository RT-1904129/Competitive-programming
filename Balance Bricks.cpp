#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;
typedef int rt;

void Balance_Bricks(vector<rt>& arr,rt & k, rt & n){
    long long int count=0;
    int min=*min_element(arr.begin(),arr.end());
     for(int i=0;i<n;++i){
         arr[i]=arr[i]-min;
         if(arr[i]>k) count+=(arr[i]-k);
     }
     cout<<count;
}


int main(){
    rt t,h,count,a;
    cin>>t>>h;
    vector<rt>arr;
    for(int i=0;i<t;++i){
        cin>>a;
        arr.push_back(a);
    }
    Balance_Bricks(arr,h,t); 
}