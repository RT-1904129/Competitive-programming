#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int Maximum_Toffees(vector<int>&array,int number_of_toffe_box_of_one_person){
    sort(array.begin(),array.end());
    int sum=0;
    for(int i=number_of_toffe_box_of_one_person;i<array.size();i=i+2){
        sum+=array[i];
    }
    return sum; 
}

int main(){
    int a,n;
    ios::sync_with_stdio(false);
    cin>>n;
    vector<int >array;
    for(int  i=0;i<n*3;++i){
        cin>>a;
        array.push_back(a);
    }
    cout<<Maximum_Toffees(array,n);
    
}