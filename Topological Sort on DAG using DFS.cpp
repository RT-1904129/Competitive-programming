#include<iostream>
#include<unordered_map>
#include <stack>
#include<vector>
using namespace std;

void DFS(vector<int>adj_list[],stack<int>&stack,vector<bool>&visited,int vertex){
    visited[vertex]=true;
    for(auto i:adj_list[vertex]){
         if(!visited[i]){
            DFS(adj_list,stack,visited,i);
        }
    }
    stack.push(vertex);
}

int main(){
    int vertex,destination,node;
    cin>>node;
    // unordered_map<int,int>array;
    vector<int>adj_list[node+1];
    for(int i=0;i<node;++i){
        cin>>vertex;
        cin>>destination;
        while(destination!=(-1)){
            adj_list[vertex].push_back(destination);
            // array[destination]++;
            cin>>destination;
        }
    }
    vector<bool>visited(node+1,false);
    stack<int>stack;
    for(int i=1;i<=node;i++){
        if(visited[i]==false){
            DFS(adj_list,stack,visited,i);
        }
    }
    while(!stack.empty()){
        cout<<stack.top()<<" ";
        stack.pop();
    }
    return 0;
}