#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
typedef long long int lli;
typedef long int li;

lli Secret_Code(string str1){
    int n=str1.length();
    if(n==1) return 1;
    lli dp[n+1];
    dp[0]=0;
    dp[1]=1;
    string str=str1.substr(0,2);
    int m=stoi(str);
    if(m<=26&&m >10){
      if(m%10 !=0) dp[2]=2;
      else dp[2]=1;
    }
    else dp[2]=1;
    if(n==2) return dp[2];
    for(int i=3;i<=n;i++){
        str=str1.substr(i-2,2);
        int m=stoi(str);
        if(m<=26&&m>9){
            if(m%10==0){
                dp[i]=dp[i-2];
            }
            else{
                dp[i]=dp[i-1]+dp[i-2];
            }
        }
        else{
            dp[i]=dp[i-1];
        }
    }
    return dp[n];
}




int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n;
    string str;
    while(n--){
        cin>>str;
        cout<<Secret_Code(str)<<" \n";
    }
}