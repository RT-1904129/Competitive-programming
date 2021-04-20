#include<iostream>
#include<queue>
#include<vector>
using namespace std;

bool BFS(vector<int>adj_list[],queue<int>&queue,vector<bool>&visited,vector<int>&arr){
    if(queue.empty())
        return false;
    int vertex=queue.front();
    queue.pop();
    if(arr[vertex]==0){
        return true;
    }
    for(auto i:adj_list[vertex]){
        if(!visited[i]){
            visited[i]=true ;
            queue.push(i);
        }
    }
    return BFS(adj_list,queue,visited,arr);
}

int main(){
    int a,b,c,vertex;
    cin>>a>>b;
    vector<int>arr;
    for(int i=0;i<a;++i){
        cin>>c;
        arr.push_back(c);
    }
    vector<int>adj_list[a+1];
    for(int i=0;i<a;++i){
        vertex=arr[i];
        if((i-vertex)>=0) adj_list[i].push_back(i-vertex);
        if((i+vertex)<a)adj_list[i].push_back(i+vertex);
        }
    vector<bool>visited(a,false);
    queue<int>queue;
    visited[b]=true;
    queue.push(b);
    if(BFS(adj_list,queue,visited,arr)) {
        cout<<"Yes";
    }
    else cout<<"No";
}