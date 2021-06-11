#include<iostream>
#include<utility>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;
typedef  long int rt;
void Ticket_Counter(){
    rt m,n,a,j=0;
    char k;
    deque<rt>array;
    cin>>m>>n;
    for(rt i=0;i<m;++i){
        array.push_back(i+1);
    }
    for(rt i=0;i<n;++i){
        cin>>k;
        if(k=='N'){
            cout<<array[0]<<" ";
            a=array[0];
            array.pop_front();
            array.push_back(a);
        }
        else{
            cin>>a;
            array.erase(remove(array.begin(),array.end(),a),array.end());
            array.push_front(a);
        }
    }
    cout<<'\n';
}

int main(){
    rt t;
    string str;
    ios::sync_with_stdio(false);
    cin>>t;
    for(rt i=0;i<t;++i){
         Ticket_Counter();
    }
}