
#include<iostream>
/* 
Auther:Rishabh Tripathi
Topic:-Pangram problem
*/
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int number,s,charracter_int,check;
    cin>>number;
    string t;
    getline(cin, t);
    for(int i=0;i<number;++i){
        string r;
        getline(cin, r);
        s=r.length();
        if(s<26){
            cout<<"No\n";   //here we check total length of alphabate
            continue;}
        string rt;  //we will try to make a string which is always have no repited string
        for(int i=0;i<s;++i){
            charracter_int=r[i];
            if ((charracter_int>=97 && charracter_int<=122)||(charracter_int>=65 && charracter_int<=90)){
                check=rt.find(tolower(r[i]));
                if(check==(-1)) rt+=tolower(r[i]);}
                }
        //cout<<rt;
        s=rt.length();
        if(s<26){
            cout<<"No\n";
            continue;}
        cout<<"Yes\n";
    }
}
