#include<iostream>
#include <stack>
#include<vector>
using namespace std;

void DFS(vector<int>adj_list[],stack<int>&stack,vector<bool>&visited){
    if(stack.empty())
        return;
    int vertex=stack.top();
    stack.pop();
    if(visited[vertex]==false){
        visited[vertex]=true;
        cout<<vertex<<" ";
    }
    for(auto i:adj_list[vertex]){
         if(!visited[i]){
            stack.push(i);
            DFS(adj_list,stack,visited);
        }
    }
    
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
    stack<int>stack;
    for(int i=1;i<=node;i++){
        if(visited[i]==false){
            stack.push(i);
            DFS(adj_list,stack,visited);
        }
    }
    return 0;
}