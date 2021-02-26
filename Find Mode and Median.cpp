/*
Author:-Rishabh Tripathi
Counting sort Algorithm "only applicable to integer value"
*/
#include <iostream>
#include<vector>
#include<climits>
using namespace std;
typedef long long int rt;
void Counting_sort(vector<rt>arr){
    rt max=LLONG_MIN,sum=0;
    rt input_arr_size=arr.size();
    pair<rt,rt>mode{0,0};
    for(rt i=0;i<input_arr_size;++i){
        if(max<arr[i]) max=arr[i];  //try to claculate maximun value in array
    }
    vector<rt>count_array(max+1);
    vector<rt>out_put_array(input_arr_size);
    for(rt i=0;i<input_arr_size;++i){
        count_array[arr[i]]++;
    }
    for(rt i=0;i<count_array.size();++i){
        if(mode.second<count_array[i]) {mode.first=i ;mode.second=count_array[i];}
    }
    for(rt i=0;i<count_array.size();++i){
        sum+=count_array[i];
        count_array[i]=sum;
    }
    for(rt i=input_arr_size-1;i>=0;--i){
        count_array[arr[i]]--;
        out_put_array[count_array[arr[i]]]=arr[i];
    }
    double median;
    if(input_arr_size%2==0){
        median=(float)(out_put_array[input_arr_size/2]+out_put_array[(input_arr_size/2)-1])/2.0;
        printf("%lld %.1lf\n",mode.first,median);
    }
    else {
        median=(float)out_put_array[input_arr_size/2];
        printf("%lld %.1lf\n",mode.first,median);
    }
}

int main() {
    rt a,b,c;
    cin>>a;
    for(rt i=0;i<a;i++){
        cin>>b;
        vector<rt>arr;
        vector<float>arr1;
        for(rt j=0;j<b;++j){
            cin>>c;
            arr.push_back(c);
        }
        Counting_sort(arr);
        // cout<<arr1[0]<<" "<<arr1[1]<<"\n";
    }
    return 0;
}