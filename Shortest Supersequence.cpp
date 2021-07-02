#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
typedef long long int lli;
typedef long int li;

int longest_Common_sequence_DP(string &arr1,string &arr2){
    int n=arr1.length(),m=arr2.length(),k;
    vector<vector<int>>arr3(n+1,vector<int>(m+1));
    for(int i=1;i<n+1;++i){
        for(int j=1;j<m+1;++j){
            if(arr1[i-1]==arr2[j-1]) arr3[i][j]= 1+arr3[i-1][j-1];
            else
                arr3[i][j]=max(arr3[i-1][j],arr3[i][j-1]);
        }
    }
    k=m+n;
    return k-arr3[n][m];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str1,str2,str3;
    cin>>str1;cin>>str2;
    // cin>>str1;
    // cout<<str1.length();
    cout<<longest_Common_sequence_DP(str1,str2);
    return 0;
}