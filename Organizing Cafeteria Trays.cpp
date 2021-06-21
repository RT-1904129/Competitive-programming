#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;
typedef int rt;

void Organizing_Cafeteria_Trays(vector<rt>&arr,vector<rt>&arr1,rt & size){
    sort(arr1.begin(),arr1.end());
    int j=0,count=0;
    for(int i=0;i<size;++i){
        while(arr[j]!=arr1[i]){
            j++;
            count++;
            if(j>=size) break;
        }
        j++;
        if(j>=size) break;
    }
    cout<<count;
}

int main(){
    rt t,h,count,a;
    cin>>t;
    vector<rt>arr,arr1;
    for(int i=0;i<t;++i){
        cin>>a;
        arr.push_back(a);
        arr1.push_back(a);
    }
    Organizing_Cafeteria_Trays(arr,arr1,t);
}