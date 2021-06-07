#include <iostream>
#include <queue>
#include <cmath> 
using namespace std;

int total_chocolates(vector<int>chocolates, int k)
{
	priority_queue<double> pq;
    int n = chocolates.size();
	for (int i = 0; i < n; i++) 
	{
		pq.push(chocolates[i]);
		
		auto max_chocolates = pq.top(); 
		if (max_chocolates > k) 
		{
			int remaining_chocolates = min(
				ceil(max_chocolates * 0.9), max_chocolates - k
			);
			pq.push(remaining_chocolates);
		}
		pq.pop();
	}
	
	long total = 0;
	while (!pq.empty()) 
	{
		auto x = pq.top(); 
		total += (long) x;
		pq.pop();
	}

	return total;
}


int main() {
	int t;
	cin >> t;
	while (t--) 
    {
	    int n, k; 
        cin >> n >> k;
        vector<int> chocolates(n);
	    for (int i = 0; i < n; i++) 
        {
            cin >> chocolates[i];
        }
        
	    cout << total_chocolates(chocolates, k) << '\n';
	}
	return 0;
}