/*
Auther- Rishabh Tripathi
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef unsigned long long int rt;
int main(){
    rt a,b,c,sum=0,j=1;
    cin>>a>>b;
    priority_queue<rt>array1;
    for(rt i=0;i<a;++i) {cin>>c;array1.push(c);}
    c=0;
    while((b--)&&(j>0)){
        sum+=array1.top();
        j=array1.top();
        array1.pop();
        array1.push(j-1);
    }
    cout<<sum;
    
}