/*
Author:-Rishabh Tripathi
Counting sort Algorithm "only applicable to integer value Here i took integer range -100 to 100 "
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
    vector<rt>count_array(max+1+100);
    vector<rt>out_put_array(arr_length);
    for(rt i=0;i<arr_length;++i){
        if(arr[i]>=0)  count_array[arr[i]+100]++;
        else count_array[100-abs(arr[i])]++;
    }
    for(rt i=0;i<count_array.size();++i){
        sum+=count_array[i];
        count_array[i]=sum;
    }
    for(rt i=arr_length-1;i>=0;--i){
        if(arr[i]>=0) {
            count_array[arr[i]+100]--;
            out_put_array[count_array[arr[i]+100]]=arr[i];
            
        }
        else{
            count_array[100-abs(arr[i])]--;
            out_put_array[count_array[100-abs(arr[i])]]=arr[i];
        }
    }
    return out_put_array;
}

int main() {
    rt a,c;
    cin>>a;
    vector<rt>arr;
    for(rt i=0;i<a;++i) {cin>>c;arr.push_back(c);}
    arr=Counting_sort(arr);
    for(rt i=0;i<a;++i) cout<<arr[i]<<" ";
    return 0;
}