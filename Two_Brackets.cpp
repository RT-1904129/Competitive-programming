#include<iostream>
#include<string>
#include<utility>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef  long int rt;

rt Two_Brackets(string &str){
    rt count=0;
    char check;
    queue<char>arr1,arr2;
    for(rt i=0;i<str.length();++i){
        if(str[i]=='(') arr1.push(str[i]);
        else if(str[i]=='[') arr2.push(str[i]);
        
        if(str[i]==')'){
            if(!arr1.empty()){
                count++;
                arr1.pop();
            }
        }
        else if(str[i]==']'){
            if(!arr2.empty()){
                count++;
                arr2.pop();
            }
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
        cin>>str;
        cout<<Two_Brackets(str)<<"\n";
    }
}