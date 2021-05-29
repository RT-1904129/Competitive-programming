#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;

unsigned int Longest_Subsequence_Length(vector<unsigned int>&array1,vector<unsigned int>&array2){
    unsigned long long int sum1=0,sum2=0,count=0;
    vector<pair<unsigned int,unsigned int>>arr;
    for(unsigned int i=0;i<array1.size();++i){
        if(array1[i]>=array2[i]){
            sum1+=array1[i];
            sum2+=array2[i];
            count++;
        }
        else{
            arr.push_back(make_pair(array2[i]-array1[i],array1[i]));
        }
    }
    sort(arr.begin(),arr.end());
    for(unsigned int i=0;i<arr.size();++i){
        sum1+=arr[i].second;
        sum2+=(arr[i].first+arr[i].second);
        if(sum1>=sum2) count++;
        else break;
    }
    return count;
}


int main() {
    unsigned int a,b;
    ios::sync_with_stdio(false);
    cin>>a;
    vector<unsigned int>array1,array2;
    for(unsigned int i=0;i<a;++i){
        cin>>b;
        array1.push_back(b);
    }
    for(unsigned int i=0;i<a;++i){
        cin>>b;
        array2.push_back(b);
    }
    cout<<Longest_Subsequence_Length(array1,array2);
    return 0;
}