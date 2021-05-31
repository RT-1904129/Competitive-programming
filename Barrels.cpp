#include<iostream>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
typedef long long int rt;

rt Barrels(priority_queue<rt>&array1,rt k){
    rt i=0,sum=array1.top();
    array1.pop();
    while(k!=0){
        if(!array1.empty()){
            sum=sum+array1.top();
            array1.pop();
        }
        else  break;
        k--;
    }
    return sum ;
}

int main(){
    rt a,m,n,k;
    ios::sync_with_stdio(false);
    cin>>n;
    for(rt i=0;i<n;++i){
        cin>>m>>k;
        priority_queue<rt>array1;
        for(long int j=0;j<m;++j){
            cin>>a;
            array1.push(a);
        }
        cout<<Barrels(array1,k)<<"\n";
    }
}