#include <iostream>
#include <vector>
using namespace std;

bool Managing_Bills(vector<int>&arr,int size){
    int five=0,tenth=0;
    for(int i=0;i<size;++i){
        if(arr[i]==5) five++;
        else if(arr[i]==10){
            five--;
            tenth++;
        }
        else if(tenth>0){
            tenth--;
            five--;
        }
        else{
            five-=3;
        }
        if(five<0) return false;
    }
    return true;
}


int main(){
    int t,n,input;
    cin>>t;
    for(int i=0;i<t;++i){
        cin>>n;
        vector<int>arr;
        for(int j=0;j<n;++j){
            cin>>input;
            arr.push_back(input);
        }
        if(Managing_Bills(arr,n)) cout<<"True\n";
        else cout<<"False\n";
    }
}