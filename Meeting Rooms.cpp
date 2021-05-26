#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n,t,a,b;
    cin>>n>>t;
    for(int i=0;i<t;++i){
        vector<pair<int,int>>array;
        int count=0;
        for(int j=0;j<n;++j){
            cin>>a>>b;
            array.push_back(make_pair(a,b));
        }
        sort(array.begin(),array.end());
        for(int j=0;j<n-1;++j){
            if(array[j].second>array[j+1].first){
                cout<<"NO ";
                break;
        }
        else cout<<"NO ";
    }
}