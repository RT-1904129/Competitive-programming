#include <iostream>
#include <vector>
#include<utility>
#include <string>
#include <climits>
#include <queue>
using namespace std;
#define me pair<int,pair<string,int>>
#define m pair<string,int>
typedef long int rt;
rt Ravis_Book_Reading(vector< m>&arr,vector<me>&array){
    rt count=0;
    m check;
    priority_queue<me,vector<me>,greater<me>>array1{array.begin(),array.end()};
    priority_queue< m,vector< m>,greater< m>>arr1{arr.begin(),arr.end()};
    while(!arr1.empty()){
        check=arr1.top();
        arr1.pop();
        count+=check.second;
        if(check.first=="MAGYK") return count;
        while((!array1.empty())&&(array1.top().first<=count)){
            arr1.push(array1.top().second);
            array1.pop();
        }
    }
}

int main(){
    int N,M,K,a,b;
    string str;
    cin >> N>>M>>K;
    vector< m> arr;
    for (int i=0;i<N;++i){
        cin >> str>>a;
        arr.push_back({str,a});
    }
    arr.push_back({"MAGYK",K});
    vector<me> array;
    for (int i=0;i<M;++i){
        cin >> b >> str >>a;
        array.push_back({b,{str,a}});
    }
    cout<<Ravis_Book_Reading(arr,array);
}