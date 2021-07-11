#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
typedef long long int lli;
typedef long int li;

bool Longest_Palindromic_Subsequence(string str1,string str2,string str3){
    int n= str1.length(),m=str2.length(),k=str3.length();
    vector<vector<int>>arr3(n+1,vector<int>(k+1));
    for(int i=1;i<n+1;++i){
        for(int j=1;j<k+1;++j){
            if(str1[i-1]==str3[j-1]) arr3[i][j]= 1+arr3[i-1][j-1];
            else
                arr3[i][j]=max(arr3[i-1][j],arr3[i][j-1]);
        }
    }
    vector<vector<int>>arr4(m+1,vector<int>(k+1));
    for(int i=1;i<m+1;++i){
        for(int j=1;j<k+1;++j){
            if(str2[i-1]==str3[j-1]) arr4[i][j]= 1+arr4[i-1][j-1];
            else
                arr4[i][j]=max(arr4[i-1][j],arr4[i][j-1]);
        }
    }
    if(k==(arr3[n][k]+arr4[m][k])) return true;
    else return false;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n;
    for(int i=0;i<n;++i){
        string str1,str2,str3;
        cin>>str1>>str2>>str3;
        if(Longest_Palindromic_Subsequence(str1,str2,str3)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}