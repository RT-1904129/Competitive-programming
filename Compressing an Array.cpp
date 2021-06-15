#include <iostream>
#include <queue>
#include<utility>
#include <vector>
#include <unordered_map>
using namespace std;

int Compressing_an_Array(vector<int>& arr,int & k){
    int sum=arr.size(),check;
    unordered_map<int,int>array;
    for(int i=0;i<k;++i){
        array[arr[i]]++;
    }
    check=sum/2;
    int count=0;
    priority_queue<int>array2;
    for(auto itr=array.begin();itr!=array.end();++itr){
        array2.push(itr->second);
    }
    while(sum>check){
        sum-=array2.top();
        array2.pop();
        count++;
    }
    return count;
}


int main(){
    int t,n,input;
    cin>>t;
    vector<int>arr;
    for(int i=0;i<t;++i){
        cin>>input;
        arr.push_back(input);
    }
    cout<<Compressing_an_Array(arr,t);
}