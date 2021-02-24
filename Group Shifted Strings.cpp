#include<iostream>
#include<unordered_map>
#include<set>
#include<string>
using namespace std;
typedef unsigned  long int rt;
int main(){
    rt a;
    cin>>a;
    unordered_multimap<rt ,string>arr;
    set<rt>chek;
    string str1;
    for(rt i=0;i<a;++i){
        cin>>str1;
        arr.insert({str1.length(),str1});
        chek.insert(str1.length());
    }
    for(auto itr=chek.begin();itr!=chek.end();++itr){
        auto range=arr.equal_range(*itr);
        set<string>word;
        for(auto nhj=range.first;nhj!=range.second;++nhj){
            string s=nhj->second;
            int o=s[0]-'a';
           for(rt m=0;m<s.length();m++){
               int f=s[m]-'a'-o;
               s[m]=char('a'+(26+f)%26);
             }
           // cout<<"checking"<<sum<<" "<<(nhj->second)<<"\n";
            word.insert(s);
        }
        cout<<word.size()<<" ";
    }
    
}