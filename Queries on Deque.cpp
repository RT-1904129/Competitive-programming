#include<iostream>
#include<utility>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;
typedef  long int rt;
void Queries_on_Deque(deque<rt>&array){
    rt m,b,a,j;
    char k;
    cin>>m;
    for(rt i=0;i<m;++i){
        cin>>a;
        if(a==0){
            a=array[0];
            array.pop_front();
            array.push_back(a);
        }
        else if(a==1){
            a=array.back();
            array.pop_back();
            array.push_front(a);
        }
        else if(a==3){
            cin>>a;
            cout<<array[a]<<" ";
        }
        else{
            cin>>j>>b;
            array[j]=b;
        }
    }
    cout<<'\n';
}

int main(){
    rt t,a;
    string str;
    ios::sync_with_stdio(false);
    cin>>t;
    deque<rt>array;
    for(rt i=0;i<t;++i){
         cin>>a;
         array.push_back(a);
    }
    Queries_on_Deque(array);
}