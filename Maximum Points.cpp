#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int Maximum_Points(vector<int>&difficuilty,vector<int>&point,vector<int>&potential){
    int Maximum_Points=0;
    sort(potential.begin(),potential.end());
    vector<pair<int, int>> challenges;
    int n = point.size();

    //pair difficulty with corresponding points.
    for (int j = 0; j < n; ++j)
        challenges.push_back({difficuilty[j], point[j]});
        
    sort(challenges.begin(), challenges.end());
    
    int i = 0,best_point=0, ans = 0;
    for (int player_level : potential){
        //find best points the current player can get
        while (i < n && player_level >= challenges[i].first){
            int new_point=challenges[i].second;
            best_point=max(best_point,new_point);
            i++;
        }
        ans +=best_point ;
    }
    return ans;
}


int main(){
    int a,m,n;
    ios::sync_with_stdio(false);
    cin>>m>>n;
    vector<int>difficuilty;
    vector<int>point;
    vector<int>potential;
    for(int i=0;i<m;++i){
        cin>>a;
        difficuilty.push_back(a);
    }
    for(int i=0;i<m;++i){
        cin>>a;
        point.push_back(a);
    }
    for(int i=0;i<n;++i){
        cin>>a;
        potential.push_back(a);
    }
    cout<<Maximum_Points(difficuilty,point,potential);
}