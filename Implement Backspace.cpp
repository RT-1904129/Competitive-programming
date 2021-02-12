#include<iostream>
#include<string>
#include<deque>
using namespace std;

typedef long long int rt;

string Implement_Backspace(string str1){            //Implement Backspace
    deque<char>str2;
    for(rt i=0;i<str1.length();++i){
        if((str1[i]=='<')&&(!str2.empty())) {
            str2.pop_back();
        }
        else if(str1[i]!='<')  str2.push_back(str1[i]) ;
    }
    
    string gh="";
    for(rt i=0;i<str2.size();++i)  gh+=str2[i];
    return gh;
}

int main(){
    rt a;
    cin>>a;
    string str1;
    for(rt i=0;i<a;++i){
        cin>>str1;
        cout<<Implement_Backspace(str1)<<"\n";
    }
}