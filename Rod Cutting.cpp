#include <bits/stdc++.h>
using namespace std;


long long int Rod_Cutting(int W, vector<int>wt, int n){
	int i, w;
	vector<vector<long long int>>K(W + 1, vector<long long int>(n+1));
	for(w = 0; w <= W; w++){
		for(i = 0; i <= n; i++){
			if (i == 0 || w == 0)
				K[w][i] = 1;
			else if (wt[i - 1] <= w)
				K[w][i] = max(wt[i - 1] *K[w - wt[i - 1]][i],K[w][i-1]);
			else
				K[w][i] = K[w][i-1];
		}
	}
	return K[W][n];
}

int main(){
	int N;
	cin>>N;
	vector<int>wt;
	for(int i=1;i<=N;++i) wt.push_back(i);
	cout << Rod_Cutting(N, wt, N);
	return 0;
}