#include<iostream>
#include<utility>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;
typedef  long int rt;

void Multiple_Queries(vector<rt>&array,vector<rt>&quarries){
    rt i=0,a,b;
    rt max_quarr=*max_element(quarries.begin(),quarries.end());
    vector<pair<rt,rt>>arra1;
    deque<rt>arr{array.begin(),array.end()};
    for(i;i<max_quarr;++i){
        a=arr.front();
        arr.pop_front();
        b=arr.front();
        arr.pop_front();
        if(a>b){
            arr.push_front(a);
            arr.push_back(b);
        }
        else{
            arr.push_front(b);
            arr.push_back(a);
        }
        arra1.push_back({arr[0],arr[1]});
    }
    for(rt i=0;i<quarries.size();++i){
        cout<<arra1[quarries[i]-1].first<<" "<<arra1[quarries[i]-1].second<<'\n';
    }
}

int main(){
    rt a,m,n,k,t;
    string str;
    ios::sync_with_stdio(false);
    cin>>n>>k;
    vector<rt>array,quarries;
    for(rt i=0;i<n;++i){
        cin>>a;
        array.push_back(a);
    }
    for(rt i=0;i<k;++i){
        cin>>a;
        quarries.push_back(a);
    }
   Multiple_Queries(array,quarries) ;
}