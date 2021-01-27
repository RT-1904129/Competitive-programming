#include<iostream>
#include <climits>
using namespace std;
typedef long long int rt;

rt sum_cross(rt array[],rt low,rt mid,rt high){
    rt right_sum=0,sum=0;
    for(rt i=low;i<=high;++i){
        sum+=array[i];
        if(array[i]<0) sum=0;
        else if(right_sum<=sum) right_sum=sum;
    }
    return(right_sum);
}


rt Maximum_Non_Negative_SubArray_Sum(rt array[],rt low,rt high){
    if(low==high) return array[low];
    else{
        rt mid=(low+high)/2 ;
        rt left_subarray_sum=Maximum_Non_Negative_SubArray_Sum(array,low,mid);
        rt right_subarray_sum=Maximum_Non_Negative_SubArray_Sum(array,mid+1,high);
        rt cross_sum=sum_cross(array,low,mid,high);
        if((right_subarray_sum>=left_subarray_sum)&&(right_subarray_sum>=cross_sum))  return right_subarray_sum;
        else if((right_subarray_sum<=left_subarray_sum)&&(left_subarray_sum>=cross_sum))  return left_subarray_sum;
        else  return cross_sum;
    }
}

int main(){
    rt a;
    cin>>a;
    rt array[a];
    for(rt i=0;i<a;++i)  cin>>array[i];
    rt output=Maximum_Non_Negative_SubArray_Sum(array,0,a-1);
    cout<<output;
}