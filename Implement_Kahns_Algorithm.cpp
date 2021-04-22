#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
void Topological_Sort_Kahn_s_algorithm(vector<int>adj_list[],unordered_map<int,int>&array,vector<bool>&visited,vector<int>&output){
    int vertex;
    queue<int>queue;
    for(int i=1;i<visited.size();++i){
        if(array[i]==0) {
            queue.push(i);
            visited[i]=true;
        }
    }
    while(!queue.empty()){
        vertex=queue.front();
        queue.pop();
        output.push_back(vertex);
        for(auto i:adj_list[vertex]){
            if((!visited[i])&&(array[i]!=0)){
                array[i]--;
                if(array[i]==0){
                    queue.push(i);
                    visited[i]=true;
                }
            }
        }
    }
}

int main() {
    int vertex,destination,node;
    cin>>node;
    unordered_map<int,int>arr;
    vector<int>adj_list[node+1];
    for(int i=0;i<node;++i){
        cin>>vertex;
        cin>>destination;
        while(destination!=(-1)){
            adj_list[vertex].push_back(destination);
            arr[destination]++;
            cin>>destination;
        }
    }
    vector<bool>visited(node+1,false);
    vector<int>output;
    Topological_Sort_Kahn_s_algorithm(adj_list,arr,visited,output);
    for(int i=1;i<=node;++i){
        if(visited[i]==false){
            cout<<-1;
            return 0;
        }
    }
    for(int i=0;i<output.size();++i){
        cout<<output[i]<<" ";
    }
    return 0;
}