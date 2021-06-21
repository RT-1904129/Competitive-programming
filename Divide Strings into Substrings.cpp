#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;
typedef int rt;

void Divide_Strings_into_Substrings(string str1){
    int count=0,start=0;
    unordered_map<char,pair<int,int>>arr;
    for(int i=0;i<str1.length();++i){
        if(arr.find(str1[i]) == arr.end()){
            arr[str1[i]].second=0;
            arr[str1[i]].first=i;
        }
        arr[str1[i]].first=i;
        arr[str1[i]].second++;
    }
    //  cout<< arr['a'].first<<" checking\n";
    vector<pair<int,int>>arr1;
    for(int i=0;i<str1.length();++i){
        if(arr[str1[i]].first==i){
            count++;
            // cout<< count<<" checking\n";
            count-=arr[str1[i]].second;
            // cout<< count<<" checking\n";
            if(count==0) {
                arr1.push_back({start,i});
                if(i+1 < str1.length()) start=i+1;
            }
        }
        else  count++;
    }
    if(count!=0) arr1.push_back({start,str1.length()-1});
    // cout<< arr1.size()<<" checking\n";
    vector<string>array;
    for(int i=0;i<arr1.size();++i){
        string str2;
        for(int j=arr1[i].first;j<arr1[i].second+1;++j){
            str2+=str1[j];
        }
        array.push_back(str2);
    }
    sort(array.begin(),array.end());
    for(int i=0;i<array.size();++i){
            cout<<array[i]<<" ";
    }
}

int main(){
    string str;
    cin>>str;
    Divide_Strings_into_Substrings(str);
}