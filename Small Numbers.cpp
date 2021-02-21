#include<iostream>
#include<map>
#include<vector>
using namespace std;
typedef long long int rt;
 
 vector<rt> Small_Numbers(vector<rt>arr){
    vector<rt>arr1;
    map<rt,rt>dic;
    for(rt i=0;i<arr.size();++i){
        if(dic.find(arr[i])==dic.end()) dic[arr[i]]=1;
        else dic[arr[i]]++;
    }
    rt count=0,temp;
    for(auto itr=dic.begin();itr!=dic.end();++itr){
            temp=itr->second;
            itr->second=count;
            count+=temp;
        }
    for(rt i=0;i<arr.size();++i){
        arr1.push_back(dic[arr[i]]);
    }
    return arr1;
 }
 
 int main(){
    rt a,b;
    scanf("%lld",&a);
    vector<rt>arr1;
    for(rt i=0;i<a;++i){
        scanf("%lld",&b);
        arr1.push_back(b);
    }
    arr1=Small_Numbers(arr1);
    for(rt i=0;i<a;++i)  printf("%lld ",arr1[i]);
    return 0;
 }