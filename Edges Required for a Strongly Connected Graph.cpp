#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int N, K, node_1, node_2;
    cin >> N >> K;
    
    // first and second element in a pair signifies outdegree and indegree respectively
    unordered_map<int, pair<int, int>> vertex_degree;
    while (K--){
        cin >> node_1 >> node_2;
        vertex_degree[node_1].first = 1;
        vertex_degree[node_2].second = 1;
    }
    
    int total_outdegree = 0, total_indegree = 0;
    for (auto i : vertex_degree){
        if (i.second.first == 1)
            total_outdegree += 1;

        if (i.second.second == 1)
            total_indegree += 1;
    }
    cout << max((N - total_outdegree), (N - total_indegree));
    return 0;
}