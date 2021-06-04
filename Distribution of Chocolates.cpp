#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef  long int rt;
bool Distribution_of_Chocolates(priority_queue<rt,vector<rt>,greater<rt>>&array,priority_queue<rt>&array1,rt & k){
    rt sum=0;
    while(!array1.empty()){
        if(array.empty()) {
            return false;
        }
        else{
            if((array1.top()+array.top())<=k) {
                sum=array1.top()+array.top();
                array1.pop();
                array.pop();
                array.push(sum);
            }
            else return false;
        }
    }
    return true;
}

int main(){
    rt a,m,n,k,t;
    ios::sync_with_stdio(false);
    cin>>t;
    for(rt i=0;i<t;++i){
        cin>>n>>m>>k;
        priority_queue<rt>array1;
        priority_queue<rt,vector<rt>,greater<rt>>array;
        for(rt i=0;i<n;++i){
            cin>>a;
            array.push(a);
        }
        for(rt i=0;i<m;++i){
            cin>>a;
            array1.push(a);
        }
        if(Distribution_of_Chocolates(array,array1,k)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}