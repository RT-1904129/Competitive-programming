#include<iostream>
#include<queue>
#include<vector>
using namespace std;

bool check_bipartite(vector<int>adj_list[],vector<bool>&visited,vector<int>&color_matrix,int vertex){
    visited[vertex]=true;
    color_matrix[vertex]=1;
    queue<int>check;
    check.push(vertex);
    while(!check.empty()){
        vertex=check.front();
        check.pop();
        for(int i:adj_list[vertex]){
            if(visited[i] && color_matrix[vertex]==color_matrix[i])
                return false;
             if (!visited[i]){
                 visited[i]=true;
                 color_matrix[i]=color_matrix[vertex]+1;
                 check.push(i);
             }
        }
    }
    return true;
}

int main(){
    int vertex,destination,node,check;
    cin>>node>>check;
    vector<int>adj_list[node+1];
    for(int i=0;i<check;++i){
        cin>>vertex;
        cin>>destination;
            adj_list[vertex].push_back(destination);
            adj_list[destination].push_back(vertex);
    }
    vector<bool>visited(node+1,false);
    vector<int >color_matrix(node+1,0);
    bool output=true;
    for(int i=1;i<=node;i++){
        if(! visited[i]){
           output&= check_bipartite(adj_list,visited,color_matrix,i);
        }
    }
    if(output)  cout<<"Yes";
    else cout<<"No";
}