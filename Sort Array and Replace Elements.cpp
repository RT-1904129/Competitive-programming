/*
Author:-Rishabh Tripathi
Counting sort Algorithm "only applicable to integer +ve  value"
*/
#include <iostream>
#include<vector>
#include<climits>
using namespace std;
typedef long long int rt;
vector<rt> Counting_sort(vector<rt>arr){
    rt max=LLONG_MIN,sum=0;
    rt arr_length=arr.size();
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
    for(rt i=arr_length-1;i>=arr_length/2;--i){
        count_array[arr[i]]--;
        out_put_array[count_array[arr[i]]]=arr[i];
    }
    for(rt i=arr_length/2-1;i>=0;--i){
        count_array[arr[i]]--;
        out_put_array[count_array[arr[i]]]=-1;
    }
    
    return out_put_array;
}

int main() {
    rt a,b;
    cin>>a;
    vector<rt>arr;
    for(rt i=0;i<a;++i){
        cin>>b;
        arr.push_back(b);
    }
    arr=Counting_sort(arr);
    for(rt i=0;i<a;++i) cout<<arr[i]<<" ";
    return 0;
}