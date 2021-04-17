#include<iostream>
#include <queue>
#include<vector>
using namespace std;

void BFS(vector<int>adj_list[],queue<int>&queue,vector<bool>&visited){
    if(queue.empty())
        return;
    int vertex=queue.front();
    queue.pop();
    cout<<vertex<<" ";
    for(auto i:adj_list[vertex]){
        if(!visited[i]){
            visited[i]=true ;
            queue.push(i);
        }
    }
    BFS(adj_list,queue,visited);
}

int main(){
    int vertex,destination,node;
    cin>>node;
    vector<int>adj_list[node+1];
    for(int i=0;i<node;++i){
        cin>>vertex;
        cin>>destination;
        while(destination!=(-1)){
            adj_list[vertex].push_back(destination);
            adj_list[destination].push_back(vertex);
            cin>>destination;
        }
    }
    vector<bool>visited(node+1,false);
    queue<int>queue;
    for(int i=1;i<=node;i++){
        if(visited[i]==false){
            visited[i]=true;
            queue.push(i);
            BFS(adj_list,queue,visited);
        }
    }
    return 0;
}