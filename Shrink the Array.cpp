#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
typedef  long int rt;
rt Shrink_the_Array(priority_queue<rt>&array){
    rt sum=0,check1,check2;
    while(array.size()>1){
        check1=array.top();
        array.pop();
        check2=array.top();
        array.pop();
        array.push(abs(check2-check1));
    }
    if(array.size()==1) return array.top();
    else return -1;
}

int main(){
    rt a,m,n,k;
    ios::sync_with_stdio(false);
    cin>>n;
    priority_queue<rt>array;
    for(rt i=0;i<n;++i){
        cin>>a;
        array.push(a);
    }
    cout<<Shrink_the_Array(array);
}