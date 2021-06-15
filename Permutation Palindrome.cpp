#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <unordered_map>
#include <unordered_set>
typedef long int rt;
using namespace std; 

void Permutation_Palindrome(string &str){
    unordered_map<char,rt>arr;
    unordered_set<char>array{str.begin(),str.end()};
    for(rt i=0;i<str.length();++i){
        arr[str[i]]++;
    }
    rt countEven=0,countOdd=0;
    for(auto itr=arr.begin();itr!=arr.end();++itr){
        if((itr->second % 2 )==0) countEven++;
        else countOdd++;
    }
    if((countEven!=0)&& (countOdd==1 || countOdd==0)) cout<<"YES\n";
    else if(array.size()==1) cout<<"YES\n";
    else cout<<"NO\n";
}

int main() {
    rt t;
    cin>>t;
    string str;
    ios::sync_with_stdio(false);
    for(rt i=0;i<t;++i){
        cin>>str;
        Permutation_Palindrome(str);
    }
}