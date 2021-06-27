#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
typedef long long int rt;

int longest_Common_sequence_DP(vector<rt>&arr1,vector<rt>&arr2){
    int n=arr1.size(),m=arr2.size();
    int arr3[n+1][m+1];
    for(int i=0;i<n+1;++i){
        for(int j=0;j<m+1;++j){
            if(i==0 || j==0) arr3[i][j]=0;
            else if(arr1[i]==arr2[j]) arr3[i][j]= 1+arr3[i-1][j-1];
            else{
                arr3[i][j]=max(arr3[i-1][j],arr3[i][j-1]);
            }
        }
    }
    return arr3[n][m];
}


int main() {
    ios::sync_with_stdio(false);
    rt n,m;
    vector<rt>arr1{1,2,3,4,5,6,7,8,4},arr2{3,4,5,6,7,10,9,4};
    cout<<longest_Common_sequence_DP(arr1,arr2);
    return 0;
}