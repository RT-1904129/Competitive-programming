#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std; 

// Defining a comparator to maintain the heap in increasing order i.e., min-heap
class compare
{
    public:
    bool operator()(const pair<int,pair<int, int> >& a, const pair<int,pair<int, int> >& b)
    {
        return a.first > b.first;
    }
};

int kth_smallest(vector<vector<int>>& matrix, int k) {
        
    int num_rows = matrix.size();
    int num_columns = matrix[0].size();
    
	priority_queue< pair<int,pair<int, int> >, vector<pair<int, pair<int, int> > >, compare > pq;
    
    int suitable_rows = min(num_rows, k);
    
    // Picking up the first element of each row, for the first iteration
    for(int i=0; i<suitable_rows; i++)
        pq.push(make_pair(matrix[i][0], make_pair(i,0) ));
    
    int least_value;
    while(k--)
    {
        least_value = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        
        pq.pop();
        
        if(j < num_columns-1)
            pq.push(make_pair(matrix[i][j+1], make_pair(i,j+1) ));
    }
    return least_value;
}


int main() {
    vector<vector<int>> matrix;
    int temp, i=1, matrix_size=0, n, k;
    
    vector<int> matrix_row;
    
    cin >> n >> k;
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            cin >> temp;
            matrix_row.push_back(temp);
        }
        matrix.push_back(matrix_row);
        matrix_row.clear();
    }

    cout << kth_smallest(matrix, k);
    
    return 0;
}