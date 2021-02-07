/*
Authur-Rishabh Tripathi
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef unsigned long long int rt;
int main(){
    rt a,b,s;
    cin>>a;
    for(rt i=0;i<a;++i){
        cin>>b;
        priority_queue<rt,vector<rt>,greater<rt>>array1;
        for(rt j=0;j<b;++j) { cin>>s;array1.push(s);}
        rt leftsum=0;
        rt rightsum=0;
            while(array1.size()!=0){
                rightsum=rightsum*10+array1.top();
                array1.pop(); 
                if(array1.size()!=0){
                    leftsum=leftsum*10+array1.top();
                    array1.pop(); 
                }
            }
        cout<<leftsum+rightsum<<"\n";
    }
}