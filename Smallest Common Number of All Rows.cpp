#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<climits>
using namespace std;
typedef long long int rt;

int main(){
    rt a,b;
    cin>>a>>b;
    rt array[a][b];
    for(rt i=0;i<a;++i){
        for(rt j=0;j<b;++j) cin>>array[i][j];
    }
    unordered_map<rt,rt>arr1;
    for(rt i=0;i<a;++i){
        unordered_set<rt>match;
        for(rt j=0;j<b;++j) match.insert(array[i][j]);
        for(auto itr=match.begin();itr!=match.end();++itr){
            if(arr1.find(*itr)==arr1.end()) arr1[*itr]=1;
            else arr1[*itr]+=1;
        }
    }
    rt min=LLONG_MAX;
    for(auto itr=arr1.begin();itr!=arr1.end();++itr){
        if((*itr).second>=a){
            if(min>=(*itr).first)   min=(*itr).first;
        }
    }
    if(min==LLONG_MAX) cout<<-1;
    else cout<<min;
}