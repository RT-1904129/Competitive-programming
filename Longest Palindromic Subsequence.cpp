#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
typedef long long int lli;
typedef long int li;

int Longest_Palindromic_Subsequence(string str){
    string str2;
    int n= str.length();
    for(int i=n-1;i>=0;--i){
        str2+=str[i];
    }
    int m=n;
    vector<vector<int>>arr3(n+1,vector<int>(m+1));
    for(int i=1;i<n+1;++i){
        for(int j=1;j<m+1;++j){
            if(str[i-1]==str2[j-1]) arr3[i][j]= 1+arr3[i-1][j-1];
            else
                arr3[i][j]=max(arr3[i-1][j],arr3[i][j-1]);
        }
    }
    return arr3[n][m];
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    string str;
    cin>>str;
    cout<<Longest_Palindromic_Subsequence(str);
    return 0;
}