#include <iostream>
#include <algorithm>
#include <vector>
#include<utility>
#include <queue>

using namespace std;
#define v vector<vector<int>>
#define pe pair<int ,pair<int,int>>

v smallestPairs(vector<int>&array1,vector<int>&array2, int & num_pairs){
    v result;
    int num_rows_array1 = array1.size();
    int num_rows_array2 = array2.size();
	priority_queue<pe, vector<pe>, greater<pe>> pq;
    
    // Picking up the first element of each row, for the first iteration
    for(int i=0; i<num_rows_array1; i++)
        pq.push(make_pair(array1[i]+array2[0], make_pair(i,0) ));
    
    int least_value;
    while(num_pairs--){
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        vector<int> count{array1[i],array2[j]};
        result.push_back(count);
        pq.pop();
        if(j < num_rows_array2-1)
            pq.push(make_pair(array1[i]+array2[j+1], make_pair(i,j+1) ));
    }
    return result;
}

int main() {
    vector<int> array1, array2;
    int m, n, temp, num_pairs;

    cin >> m;
    for (int i=0; i < m; i++) {
        cin >> temp;
        array1.push_back(temp);
    }
    
    cin >> n;
    for (int i=0; i < n; i++) {
        cin >> temp;
        array2.push_back(temp);
    }
    
    cin >> num_pairs;
    
    v pairs;
    pairs = smallestPairs(array1, array2, num_pairs);
    
    for (int i=0; i<pairs.size(); i++)
        cout << pairs[i][0] << " " << pairs[i][1] <<"\n";
        
    return 0;
}