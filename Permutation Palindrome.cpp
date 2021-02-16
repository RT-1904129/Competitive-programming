#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

typedef long long int rt;
rt Permutation_Palindrome(string str1){
    unordered_map<char,rt>array1;
    rt count=0,count_dublication=0;
    for(rt i=0;i<str1.length();++i){
        if(array1.find(str1[i])==array1.end()) array1[str1[i]]=1;
        else array1[str1[i]]+=1;
    }
    for(auto itr=array1.begin();itr!=array1.end();++itr){
        if(((*itr).second%2)!=0) count++;
        else count_dublication++;
    }
    if(count==1) return 1;
    else if(count_dublication==array1.size()) return 1;
    else return 0;
}

int main(){
    rt a;
    string arr1;
    cin>>a;
    for(rt i=0;i<a;++i){
        cin>>arr1;
        if(Permutation_Palindrome(arr1))  cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}