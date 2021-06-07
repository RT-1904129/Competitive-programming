#include<iostream>
#include<string>
#include<utility>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef  long int rt;

rt Leader_of_Tribe(vector<pair<rt,rt>>&arr,rt &final_year){
    rt i=2020;
    pair<rt,rt> start;
    priority_queue<pair<rt,rt>,vector<pair<rt,rt>>,greater<pair<rt,rt>>>array{arr.begin(),arr.end()};
    priority_queue<pair<rt,rt>>array2;
    arr[0]={arr[0].second,arr[0].first};
    while(final_year--){
        while((!array.empty())&&(array.top().first==(i+1))){
            start={array.top().second,array.top().first};
            array.pop();
            array2.push(start);
        }
        if(array2.top()==arr[0]) return i+1;
        else {
            array2.pop();
        }
        i++;
    }
    return -1;
}

int main(){
    rt a,m,n,final_year;
    ios::sync_with_stdio(false);
    cin>>final_year>>n;
    vector<pair<rt,rt>>arr;
    for(rt i=0;i<n;++i){
        cin>>a>>m;
        arr.push_back({a,m});
    }
    cout<<Leader_of_Tribe(arr,final_year);
}