#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
typedef unsigned long long int ulli;
typedef long long int lli;
typedef long int li;

lli Maximum_Loot_in_a_Matrix(vector<vector<int>> &arr,int &n,int& m){
    vector<vector<lli>>arr1(n,vector<lli>(m));
    
    if(m==1 && n==1) return (lli)arr[0][0]; 
    else if(n==1) {
        arr1[0][0]=arr[0][0];
        for(int j=1;j<m;++j) arr1[0][j]=arr1[0][j-1]+arr[0][j];
        return arr1[0][m-1];
    }
    else if(m==1){
        lli maxu=arr[0][0];
        for(int j=1;j<n;++j) maxu=max(maxu,(lli)arr[j][0]);
        return maxu;
    }
   for(int j=0;j<m;++j){
        for(int i=n-1;i>=0;--i){
            if(j==0) arr1[i][j]=arr[i][j];
            else if(i==0) arr1[i][j]=max(arr1[i][j-1],arr1[i+1][j-1])+arr[i][j] ;
            else if(i== n-1) arr1[i][j]=max(arr1[i][j-1],arr1[i-1][j-1])+arr[i][j] ;
            else arr1[i][j]=max(arr1[i-1][j-1],max(arr1[i][j-1],arr1[i+1][j-1]))+arr[i][j];
        }
    }
    lli maxi=arr1[0][m-1];
    for(int i=1;i<n;++i){
        maxi=max(arr1[i][m-1],maxi);
    }
    return maxi;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,t;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>arr[i][j];
        }
    }
    cout<<Maximum_Loot_in_a_Matrix(arr,n,m);
    return 0;
}