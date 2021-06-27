#include <bits/stdc++.h>
using namespace std;
bool Check_Subset_Sum(int W,vector<int>&arr,int n){
    vector<vector<bool>> subset(W + 1, vector<bool>(n + 1));
    for(int i=0;i<=n;++i) subset[0][i]=true;
    for(int i=1;i<=W;++i) subset[i][0]=false;
    for(int i=1;i<=W;++i){
        for(int j=1;j<=n;++j){
            if(i < arr[j-1])    
                subset[i][j]=subset[i][j-1];
            else
                subset[i][j]=subset[i][j-1] || subset[i-arr[j-1]][j-1] ;
        }
    }
    return subset[W][n];
}



int main(){
    int t,W,n;
    cin>>t;
    for(int i=0;i<t;++i){
	    cin>>n>>W;
	    vector<int>wt(n);
	    for(int j=0;j<n;++j){
	        cin>>wt[j];
	    }
	    if(Check_Subset_Sum(W, wt, n)) cout<<"True\n";
	    else cout<<"False\n";
    }
	return 0;
}