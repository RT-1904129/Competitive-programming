#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef unsigned long long int rt;

int main(){
    rt a,b,d,sum;
    cin>>a;
    for(rt i=0;i<a;++i){            //Bind Ropes
        cin>>b;
        sum=0;
        priority_queue<rt,vector<rt>,greater<rt>>array1;
        for(rt j=0;j<b;++j){
            cin>>d;
            array1.push(d);
        }
        while(array1.size()!=1){
            d=array1.top();
            array1.pop();
            b=array1.top();
            array1.pop();
            sum+=(d+b);
            array1.push(d+b);
        }
        cout<<sum<<"\n";
    }
}