#include <iostream>
#include <queue> 
#include <vector>
using namespace std;

int Maximum_Sum_of_Array_with_modification(vector<int>& arr,int & k){
    priority_queue<int,vector<int>,greater<int>>array(arr.begin(),arr.end());
    int sum=0,check=0;
    while(k--){
        check=array.top();
        array.pop();
        if(check<0) array.push(abs(check));
        else array.push(-1*check);
    }
    while(!array.empty()){
        sum+=array.top();
        array.pop();
    }
    return sum;
}


int main(){
    int t,n,input;
    cin>>t>>n;
    vector<int>arr;
    for(int i=0;i<t;++i){
        cin>>input;
        arr.push_back(input);
    }
    cout<<Maximum_Sum_of_Array_with_modification(arr,n);
}