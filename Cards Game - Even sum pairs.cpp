#include<iostream>
#include<queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    typedef long long int rt;
    rt a,count=0,b;
    cin>>a;
    queue<rt>array1;
    queue<rt>array2;
    for(rt i=0;i<a;++i) {cin>>b; array1.push(b);}
    while(a!=count){
        a=array1.size();
        count=0;
        while(!array1.empty()){
            b=array1.front();
            array1.pop();
            if((!array1.empty())&&((b+array1.front())%2)==0)   array1.pop();
            else array2.push(b);
            }
        count=array2.size();
        while(!array2.empty()){
            array1.push(array2.front());
            array2.pop();
        }
    }
    cout<<count;
}