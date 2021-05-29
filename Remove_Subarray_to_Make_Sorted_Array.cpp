#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

long int Remove_Subarray_to_Make_Sorted_Array(vector<long int>&array){
    long int i=0,n=array.size();
    long int j=n-1;
    for(;j>0;--j){
        if(array[j-1]>array[j]) break;
    }
    if(j==0) return 0;
    long int small=j;
    for(;i<n;++i){
        if((i > 0)&&(array[i] < array[i-1])) break;
        while(j<n && array[i] > array[j]) ++j;
        small=min(small,j-i-1);
    }
    return small;
}

int main(){
    long int a,m,n,target;
    ios::sync_with_stdio(false);
    cin>>m;
    vector<long int>array1;
    for(long int j=0;j<m;++j){
        cin>>a;
        array1.push_back(a);
    }
    cout<<Remove_Subarray_to_Make_Sorted_Array(array1);
}