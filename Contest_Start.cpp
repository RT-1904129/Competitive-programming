#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long int rt;
 
rt Contest_Start(rt &n,rt&x,rt&t){
   rt su= max(0LL,n-t/x)*(t/x) + min(n-1,t/x -1)*min(n,t/x)/2;
   return su;
}
 
 
int main() {
    ios::sync_with_stdio(false);
    rt test,x,n,t;
    cin>> test;
    while(test--){
        cin>> n >> x >> t;
        cout<<Contest_Start(n,x,t);
        if(test) cout<<"\n";
    }
    return 0;
}