#include <iostream>
using namespace std;

long int numberOfPaths(int m, int n){
    long int dp[n]={0};
    dp[0] = 1;
    
    for (int i = 0; i < m; i++){
        for (int j = 1; j < n; j++){
            dp[j] += dp[j - 1];
        }
    }
    return dp[n - 1];
}

int main(){
    int m, n;
    cin >> m >> n;
    cout << numberOfPaths(m, n);
}