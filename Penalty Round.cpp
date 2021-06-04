#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
typedef unsigned long int rt;
rt Penalty_Round(priority_queue<rt>&array,rt& k,rt& size){
    rt sum=0,check;
    for(rt i=0;i<k;++i){
        check=array.top()/2;
        array.pop();
        array.push(check);
    }
    for(rt i=0;i<size;++i){
        sum+=array.top();
        array.pop();
    }
    return sum;
}

int main(){
    rt a,m,n,k;
    ios::sync_with_stdio(false);
    cin>>n>>k;
    priority_queue<rt>array;
    for(rt i=0;i<n;++i){
        cin>>a;
        array.push(a);
    }
    cout<<Penalty_Round(array,k,n);
}