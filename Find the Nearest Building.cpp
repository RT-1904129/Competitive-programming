#include<iostream>
#include<utility>
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;

void BFS(vector<pair<int,int>>adj_list[],priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>&arr,int &vertex,unordered_map<int,int>&hospital){
    int minimum_dist=1000;
    int minimum_vertex;
    for(auto i:adj_list[vertex]){
        if((i.second < minimum_dist)&&(hospital[i.first]==0)) {
            minimum_dist=i.second;
            minimum_vertex=i.first;
        }
    }
    if(minimum_dist!=1000) arr.push(make_pair(minimum_dist,minimum_vertex)) ; 
}

int main(){
    int vertex1,vertex2,destination,node,route,NoHospital,b;
    cin>>node>>route>>NoHospital;
    vector<int>hospital;
    unordered_map<int,int>array;
    for(int i=0;i<NoHospital;++i){
        cin>>b;
        array[b]++;
        hospital.push_back(b);
    }
    vector<pair<int,int>>adj_list[node+1];
    for(int i=0;i<route;++i){
        cin>>vertex1>>vertex2>>destination;
        adj_list[vertex1].push_back(make_pair(vertex2,destination));
        adj_list[vertex2].push_back(make_pair(vertex1,destination));
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>arr;
    for(int i=0;i<NoHospital;i++){
        BFS(adj_list,arr,hospital[i],array);
    }
    if(!arr.empty()) cout<<arr.top().second<<" "<<arr.top().first;
    else cout<<-1;
    return 0;
}