#include <iostream>
#include <deque>
#include <string>
using namespace std;

typedef long long int rt;
string Broken_Key(string a){
    rt k=0;
    deque<char>str1;
    for(rt i=0;i<a.length();++i){
        if(a[i]=='<')   k=0;
        else if(a[i]=='>')  k=str1.size();
        else {
            str1.insert(str1.begin()+k,a[i]);
            k++;
        }
    }
    string ade="";
    for(rt i=0;i<str1.size();++i) ade+=str1[i];
    return ade;
}

int main(){
    rt a;
    cin>>a;
    string str1;
    for(rt i=0;i<a;++i){
        cin>>str1;
        str1=Broken_Key(str1);
        cout<<str1<<"\n";
    }
}