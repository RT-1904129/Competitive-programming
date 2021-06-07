#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

int kth_smallest_number(vector<pair<int, int>> &arr, int k)
{
    int n = arr.size();
	priority_queue<pair<int, int>,
				vector<pair<int, int> >,
				greater<pair<int, int> > >
		pq(arr.begin(), arr.end());

	int count = 1;
	while (count < k) {
		pair<int, int> interval = pq.top();
	
		pq.pop();

		if (interval.first < interval.second) {
			pq.push({ interval.first + 1, interval.second });
		}

		count++;
	}
	return pq.top().first;
}


int main()
{
    int n, k, p, q;
    cin >> n >> k;

    vector<pair<int, int>> arr;
    for (int i=0; i < n; i++) {
        cin >> p >> q;
        arr.push_back({p, q});
    }

	cout << kth_smallest_number(arr, k);
	return 0;
}