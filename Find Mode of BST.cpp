#include <bits/stdc++.h>
using namespace std;


int main(){
    string n;
    unordered_map<int,int>a;
    while(cin>>n){
        if (n=="null"){
            continue;
        }
        else{
            a[stoi(n)]++;
        }
    }
    int max_index=0,max_value= 0,check;
    for(auto itr=a.begin();itr!=a.end();++itr){
        if(itr->second > max_value) {
            max_index=itr->first;
            max_value=itr->second;
        }
    }
    cout<< max_index;
}