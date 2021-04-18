#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int a,b,c;
    cin>>a;
    unordered_map<int,int>arr;
    cin>>b>>c;
    while(b!=-1){
        arr[c]++;
        if(arr[b]!=0) arr[b]=0;
        cin>>b>>c;
    }
    for(auto itr=arr.begin();itr!=arr.end();++itr){
        if(itr->second>=a-1){
            cout<<itr->first;
            return 0;
        }
    }
    cout<<-1;
    return 0;
    
}