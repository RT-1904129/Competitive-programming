/*
Authur-Rishabh Tripathi
*/
#include<iostream>
#include<queue>
using namespace std;
typedef long long int rt;
int main(){
    rt a,b,c,d;
    cin>>a;
    for(rt i=0;i<a;++i){
        cin>>b;
        priority_queue<rt>array1;
        for(rt j=0;j<b;++j) { cin>>c; array1.push(c);}
        while(array1.size()!=1){
            if(array1.size()==0) break;
            c=array1.top();
            array1.pop();
            d=array1.top();
            array1.pop();
            if(c>d) array1.push(c-d);
            else if(c<d) array1.push(d-c);
        }
        if(array1.size()!=0) cout<<array1.top()<<"\n";
        else cout<<0<<"\n";
    }
}