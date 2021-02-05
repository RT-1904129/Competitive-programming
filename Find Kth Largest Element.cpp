/*
Auther- Rishabh Tripathi
*/
#include<iostream>
#include<queue>
using namespace std;
typedef long long int rt;
int main(){
    rt a,b,c;
    cin>>a>>b;
    priority_queue<rt>array1;
    for(rt i=0;i<a;++i) {cin>>c;array1.push(c);}
    for(rt i=0;i<b;++i){
        c=array1.top();
        array1.pop();
    }
    cout<<c;
}