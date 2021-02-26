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
    for(rt i=0;i<arr.size();++i){
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
    
    return out_put_array;
}

int main() {
    vector<rt>arr={4,2,2,8,3,6,10,6,8,9,56,34,89},arr1;
    arr1=Counting_sort(arr);
    for(rt i=0;i<arr1.size();++i) cout<<arr1[i]<<" ";
    return 0;
}