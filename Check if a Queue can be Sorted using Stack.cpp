#include <iostream>
#include <queue>
#include<stack>
using namespace std;
int main(){
    typedef long long int rt;
    ios::sync_with_stdio(false);
    rt d,a,b,c;
    cin>>d;
    for(rt i=0;i<d;++i){
        queue<rt>queue1;
        queue<rt>queue2;
        stack<rt>stack1;
        c=0;
        cin>>a;
        while(a!=0){
            queue1.push(a);
            cin>>a;
            c++;
        }
        while(!queue1.empty()){
            a=queue1.front();
            if(queue1.back()>a) {
                queue1.pop();
                if((!queue1.empty())&&(a>queue1.front())) stack1.push(a);
                else {
                    if ((!stack1.empty())&&(stack1.top()<a)){
                        while((!stack1.empty())&&(stack1.top()<a)) {
                        queue2.push(stack1.top());
                        stack1.pop();
                        }
                        stack1.push(a);
                    }
                    else queue2.push(a);
            }}
            else {
                if((!stack1.empty())&&(stack1.top()<a)) {
                    while((!stack1.empty())&&(stack1.top()<a)) {
                        queue2.push(stack1.top());
                        stack1.pop();
                        }}
                stack1.push(a);
                queue1.pop();
        }}
        while(!stack1.empty()){
            queue2.push(stack1.top());
            stack1.pop();
        }
        a=0;
        while(!queue2.empty()){
            b=queue2.front();
            //cout<<b;
            a++;
            queue2.pop();
            if((!queue2.empty())&&(b>queue2.front())){
                cout<<"NO\n";
                break;
            }
        }
        if(a==c) cout<<"YES\n";}
    
}