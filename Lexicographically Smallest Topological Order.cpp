#include<iostream>
#include<algorithm>
#include <stack>
#include<vector>
using namespace std;
#define gray 1
#define black 2

bool compare(int x,int y){
    return(x>y);
}
void DFS(vector<int>adj_list[],stack<int>&stack,vector<bool>&visited,int vertex,bool &iscyclic,vector<int>&colorvertex){
    visited[vertex]=true;
    colorvertex[vertex]=gray;
    for(auto i:adj_list[vertex]){
        if(!visited[i]){
            DFS(adj_list,stack,visited,i,iscyclic,colorvertex);
        }
        else if(visited[i]&&(colorvertex[i]==gray)&&colorvertex[vertex]==gray) {
            iscyclic=true;
        }
    }
    colorvertex[vertex]=black;
    stack.push(vertex);
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
            cin>>destination;
        }
    }
    bool iscyclic=false;
    for (int i=1; i<=node; i++)
        sort(adj_list[i].begin(), adj_list[i].end(), compare);
    vector<bool>visited(node+1,false);
    vector<int> color(node+1, 0);
    stack<int>stack;
    for(int i=node;i>=1;i--){
        if(visited[i]==false){
            DFS(adj_list,stack,visited,i,iscyclic,color);
        }
    }
    if(iscyclic){
        cout<<-1;
        return 0;
    }
    while(!stack.empty()){
        cout<<stack.top()<<" ";
        stack.pop();
    }
    return 0;
}