#include <iostream>
#include<vector>
using namespace std;
typedef unsigned long long int ull;

ull get_count(int &n,vector<char>&vi){
    vector<ull>arr(n);
    arr[0]=1;arr[1]=2;
    ull sum=3;
    for(int i=2;i<n;++i){
        arr[i]=sum+1;
        sum+=arr[i];
    }
    ull count=0;
    for(int i=n-1;i>=0;--i){
        if(vi[i]=='R') count+=arr[n-i-1];
    }
    return count;
}

int main(){
    int n = 0;
    char a;
    cin >> n;
    vector<char>arr;
    for(int i=0;i<n;++i) {cin>>a; arr.push_back(a);}
    cout << get_count(n,arr);
    return 0;
}