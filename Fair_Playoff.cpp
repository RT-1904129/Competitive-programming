#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef  long int rt;

void Fair_Playoff(priority_queue<rt>&array1,vector<rt>&arr){
    rt first,second,first_index,second_index;
    first=array1.top();
    array1.pop();
    second=array1.top();
    for(rt i=0;i<4;++i){
        if(arr[i]==first) first_index=i;
        if(arr[i]==second) second_index=i;
    }
    if(first_index<=1 && second_index>1) cout<<"YES\n";
    else if (first_index>1 && second_index<=1) cout<<"YES\n";
    else cout<<"NO\n";
}



int main(){
    rt a,t;
    ios::sync_with_stdio(false);
    cin>>t;
    for(rt i=0;i<t;++i){
        vector<rt>arr;
        priority_queue<rt>array1;
        for(rt j=0;j<4;++j){
            cin>>a;
            arr.push_back(a);
            array1.push(a);
        }
        Fair_Playoff(array1,arr);
    }
}