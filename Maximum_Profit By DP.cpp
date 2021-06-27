#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
typedef  int rt;

int Maximum_Profit( vector<int>wt, int n,int W){
	int i, w,including_i,excluding_i;
	vector<vector<int>>K(W + 1, vector<int>(n+1));
	for(w = 0; w <= W; w++){
		for(i = 0; i <= n; i++){
			if (i == 0 || w == 0)
				K[w][i] = 0;
			else if (w < i)
				K[w][i] =K[w][i-1] ;
			else
				K[w][i] = max(wt[i - 1] +K[w-i][i] ,K[w][i-1]);
		}
	}
	return K[W][n];
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    rt n,m;
    cin>>n;
    vector<rt>arr(n);
    for(rt i=0;i<n;++i) cin>>arr[i];
    cout<<Maximum_Profit(arr,n,n);
    return 0;
}