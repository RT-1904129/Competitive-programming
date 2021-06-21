#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
typedef long long int rt;

void Regular_Bracket_Sequence(string &str){
    int n=str.length();
    if(n%2 !=0) {
        cout<<"NO\n";
        return;
    }
    
    if(str.find('?')==-1){
        stack<char>arr;
        for(int i=0;i<n;++i){
            if(str[i]=='(') arr.push(str[i]);
            else {
                if(!arr.empty()) arr.pop();
                else {
                    cout<<"NO\n";
                    return;
                }
            }
        }
        if(arr.size()==0) cout<<"YES\n";
        else cout<<"NO\n";
        return;
    }
    
    if(str[0]!=')' && str[n-1]!='(') cout<<"YES\n";
    else cout<<"NO\n";
}



int main(){
    int t,a,b;
    string str;
    ios::sync_with_stdio(false);
    cin>>t;
    for(int i=0;i<t;++i){
        cin>>str;
        Regular_Bracket_Sequence(str);
    }
}