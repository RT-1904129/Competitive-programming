#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
typedef long int rt;
using namespace std; 

void Dungeon(vector<rt>&arr){
    if(((arr[0]+arr[1]+arr[2])%9) !=0) cout<<"NO\n";
    else{
        if(*min_element(arr.begin(),arr.end())>= ((arr[0]+arr[1]+arr[2])/9 )) cout<<"YES\n";
        else cout<<"NO\n";
    }
}


int main() {
    rt t,a;
    ios::sync_with_stdio(false);
    cin>>t;
    for(rt j=0;j<t;++j){
        vector<rt>arr;
        for(rt i=0;i<3;++i){
            cin>>a;
            arr.push_back(a);
        }
        Dungeon(arr);
    }
}