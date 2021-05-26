#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int Total_number_of_Packets(vector<int>&array,int max_capacity){
    int count=0,i=0,j=array.size()-1;
    sort(array.begin(),array.end());
    while(i<=j){
        if(array[i]+array[j] > max_capacity){
            j--;
        }
        else{
            i++;
            j--;
        }
        count++;
    }
    return count;
}


int main(){
    ios::sync_with_stdio(false);
    vector<int>array;
    int n,x,a;
    cin>>n>>x;
    for(int i=0;i<n;++i){
        cin>>a;
        array.push_back(a);
    }
    cout<<Total_number_of_Packets(array,x);
}