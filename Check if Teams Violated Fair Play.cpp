#include<iostream>
#include<unordered_map>
#include<algorithm>
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
    unordered_map<int,int>intraceted_people;
    vector<int>adj_list[node+1];
    for(int i=0;i<check;++i){
        cin>>vertex;
        cin>>destination;
        intraceted_people[vertex]=1;
        intraceted_people[destination]=1;
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
    int odd=0 ,even=0;
    for(int i=1;i<=node;++i) {
        if(intraceted_people[i]==0) continue;
        if((color_matrix[i]%2)==0) even++;
        else odd++;
    }
    if(output)  {
        cout<<"Yes\n"<<max(odd,even);
    }
    else cout<<"No";
}