/*
Author:-Rishabh Tripathi
Counting sort Algorithm "only applicable to integer value Here i took integer range -100 to 100 "
*/
#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;
typedef long long int rt;
string Counting_sort(string arr){
    rt max=LLONG_MIN,sum=0;
    rt arr_length=arr.length();
    for(rt i=0;i<arr_length;++i){
        if(max<arr[i]) max=arr[i];  //try to claculate maximun value in array
    }
    vector<rt>count_array(max+1);
    vector<rt>out_put_array(arr_length);
    for(rt i=0;i<arr_length;++i){
        count_array[arr[i]]++;
    }
    for(rt i=0;i<count_array.size();++i){
        sum+=count_array[i];
        count_array[i]=sum;
    }
    for(rt i=arr_length-1;i>=0;--i){
        count_array[arr[i]]--;
        out_put_array[count_array[arr[i]]]=arr[i];
    }
    string str2="";
    char j;
    for(rt i=0;i<arr_length;++i){
        j=out_put_array[i];
        str2+=j;}
    return str2;
}

int main() {
    rt a,c,count=0;
    cin>>a;
    for(rt i=0;i<a;++i){
        string str1,str2;
        cin>>str1;
        str1=Counting_sort(str1);
        cin>>c;
        vector<string>arr;
        for(rt i=0;i<c;++i) {cin>>str2; arr.push_back(str2);}
        for(rt i=0;i<c;++i){
            for(rt j=i+1;j<c;++j){
                str2=arr[i]+arr[j];
                str2=Counting_sort(str2);
                if(str1==str2) {cout<<1<<'\n'; count=1;break;}
                
            }
            if(count==1){
                break;
            }
        }
        if(count!=1) cout<<0<<'\n';
        count=0;
        // for(rt i=0;i<a;++i) cout<<arr[i]<<" ";
    }
    return 0;
}