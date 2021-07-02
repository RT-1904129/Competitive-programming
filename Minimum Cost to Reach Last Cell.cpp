#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int minCost(vector<vector<int>> cost){
    int n=cost[0].size(),m=cost.size();
    vector<vector<int>>arr(m,vector<int>(n));
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            arr[i][j]=cost[i][j];
            if(i==0 && j>0) 
                arr[i][j]+=arr[i][j-1];
            else if(j==0 && i>0) 
                arr[i][j]+=arr[i-1][j];
            else if(i>0 && j>0) 
                arr[i][j]+=min(arr[i-1][j],arr[i][j-1]);
        }
    }
    return arr[m-1][n-1];
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> cost(m, vector<int>(n));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];
    }
    cout << minCost(cost);
    return 0;
}