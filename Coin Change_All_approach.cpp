#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long int lli;
typedef long int li;

lli Coin_change(vector<int>&arr,int size,int amount){
    vector<vector<lli>>arr1(amount+1,vector<lli>(size));
    lli exclude_i,include_i;
    for(int i=0;i<=amount;++i){
        for(int j=0;j<size;++j){
            if(i==0) arr1[i][j]=1;
            else{
                include_i=(i>=arr[j])?arr1[i-arr[j]][j]:0;
                exclude_i=(j>=1)?arr1[i][j-1]:0;
                arr1[i][j] = include_i+exclude_i;
            }
        }
    }
    return arr1[amount][size-1];
 }
/*
lli Coin_change(vector<int>&arr,int size,int amount){
    if(amount==0)  return 1;
    if(size<=0 || amount<0) return 0;
    
    else return Coin_change(arr,size,amount-arr[size-1]) + Coin_change(arr,size-1,amount) ;
}*/




int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>m>>n;
    vector<int>arr(m);
    for(int i=0;i<m;++i)  cin>>arr[i];
    cout<<Coin_change(arr,m,n);
    return 0;
}