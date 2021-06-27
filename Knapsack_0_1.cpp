#include <bits/stdc++.h>
using namespace std;

int knapSack_0_1(int W, vector<int>wt, vector<int>val, int n){
	int i, w;
	vector<vector<int>>K(n + 1, vector<int>(W+1));
	for(i = 0; i <= n; i++){
		for(w = 0; w <= W; w++){
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] +K[i - 1][w - wt[i - 1]],K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	return K[n][W];
}

int main(){
	vector<int> val{ 60, 100, 120,200 };
	vector<int>wt{ 10, 20, 30,50 };
	int W = 40;
	int n = val.size();
	cout << knapSack_0_1(W, wt, val, n);
	
	return 0;
}

// This code is contributed by Debojyoti