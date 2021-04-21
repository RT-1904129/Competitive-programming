#include<iostream>
#include<unordered_map>
#include<utility>
#include <queue>
#include<vector>
using namespace std;

void Optimal_Allocation_of_Doctors(vector<int>adj_list[],queue<int>&queue,vector<bool>&visited,int strength){
    if(queue.empty())
        return;
    int vertex=queue.front();
    queue.pop();
    for(auto i:adj_list[vertex]){
        if(strength==0) {
            return;
        }
        if(!visited[i]){
            visited[i]=true ;
            // cout<<"checking"<<i<<"\n";
            queue.push(i);
        }
    }
   Optimal_Allocation_of_Doctors(adj_list,queue,visited,strength-1);
}

int main(){
    int vertex,destination,node,Nodoctor;
    cin>>node>>Nodoctor;
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
    vector<pair<int,int>>doctor;
    int power,doctor_value;
    for(int i=0;i<Nodoctor;++i){
        cin>>doctor_value;
        cin>>power;
        doctor.push_back(make_pair(doctor_value,power+1));
    }
    vector<bool>visited(node+1,false);
    queue<int>queue;
    for(int i=0;i<Nodoctor;++i){
        if(visited[doctor[i].first]==false){
            visited[doctor[i].first]=true;
            queue.push(doctor[i].first);
            Optimal_Allocation_of_Doctors(adj_list,queue,visited,doctor[i].second-1);
            doctor[i].second=-1;
            while(!queue.empty()) queue.pop();
        }
    }
    for(int i=1;i<=node;++i){
        if(visited[i]==false){
            cout<<"No";
            return 0;
        }
    }
    for(int i=0;i<Nodoctor;++i){
        // cout<<itr->second<<" ";
        if(doctor[i].second!=-1){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}