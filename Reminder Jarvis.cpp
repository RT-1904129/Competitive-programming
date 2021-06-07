#include<iostream>
#include<unordered_map>
#include<utility>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef  long int rt;

void Reminder_Jarvis(vector<pair<rt,rt>>&array,unordered_map<rt,rt>&array2,rt& k){
    pair<rt,rt> test;
    priority_queue<pair<rt,rt>,vector<pair<rt,rt>>,greater<pair<rt,rt>>>arr{array.begin(),array.end()};
    while(k--){
        test=arr.top();
        arr.pop();
        cout<<test.second<<" ";
        test.first=test.first+array2[test.second];
        arr.push(test);
    }
    
}

int main(){
    rt a,m,n,k,t;
    string str;
    ios::sync_with_stdio(false);
    cin>>n>>k;
    vector<pair<rt,rt>>array;
    unordered_map<rt,rt>array2;
    for(rt i=0;i<n;++i){
        cin>>a>>t;
        array.push_back({t,a});
        array2[a]=t;
    }
    Reminder_Jarvis(array,array2,k);
}