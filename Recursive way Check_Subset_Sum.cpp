#include <bits/stdc++.h>
using namespace std;
bool Check_Subset_Sum(int W,vector<int>&arr,int n,int sum){
    if(sum==W) return true;
    if((n<=0)||(sum>W)) return false;
    else return(Check_Subset_Sum(W,arr,n-1,sum+arr[n-1]) || Check_Subset_Sum(W,arr,n-1,sum));
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
	    if(Check_Subset_Sum(W, wt, n,0)) cout<<"True\n";
	    else cout<<"False\n";
    }
	return 0;
}