#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    int a,m,n;
    ios::sync_with_stdio(false);
    cin>>m>>n;
    vector<int>array;
    for(int i=0;i<m;++i){
        cin>>a;
        array.push_back(a);
    }
    int min_difference=INT_MAX,difference=0;
    sort(array.begin(),array.end());
    for(int i=0;i<=m-n;++i){
        difference=array[i+n-1]-array[i] ;
        if(difference<min_difference) min_difference=difference;
    }
    cout<<min_difference;
}