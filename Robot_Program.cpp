#include<iostream>
#include<string>
#include<utility>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;
typedef  long int rt;

rt Robot_Program(rt &a,rt&b){
    rt count=0;
    while(a||b){
        if((a!=0)&&(b!=0)){
            count+=2;
            a--;
            b--;
        }
        else if(a==0){
            if(b>1) count+=2;
            else count++;
            b--;
        }
        else if(b==0){
            if(a>1) count+=2;
            else count++;
            a--;
        }
    }
    return count;
}


int main(){
    rt t,a,b;
    string str;
    ios::sync_with_stdio(false);
    cin>>t;
    for(rt i=0;i<t;++i){
        cin>>a>>b;
        cout<<Robot_Program(a,b)<<"\n";
    }
}