#include <iostream>
#include <climits>
using namespace std;

typedef long long int rt;
rt sum_array(rt array[],rt low,rt mid,rt high){
    rt count=0,sum=LLONG_MIN;
    for(rt i=mid;i>=low;--i){
        count+=array[i];
        if (sum<=count) sum=count ;
    }
    rt left_sum=sum;
    sum=LLONG_MIN;count=0;
    for(rt i=mid+1;i<=high;++i){
        count+=array[i];
        if (sum<=count) sum=count ;
    }
    rt right_sum=sum;
    return(right_sum+left_sum);
}
rt max_subarray(rt array[],rt low,rt high){
    if(low==high){
        return array[low];
    }
    else {
        rt mid=(low+high)/2 ;
        rt left_subarray=max_subarray(array,low,mid);
        rt right_subarray=max_subarray(array,mid+1,high);
        rt sum=sum_array(array,low,mid,high);
        if((left_subarray>=right_subarray)&&(left_subarray>=sum)) {
            return left_subarray;
        }
        else if((right_subarray>=left_subarray)&&(right_subarray>=sum)) {
            return right_subarray;
        }
        else {return sum;}
    }
}

int main(){
    rt n;
    cin >> n;
    rt array[n];
    for (rt i = 0; i < n; i++)  cin >> array[i];
    rt sum = max_subarray(array, 0, n - 1);
    cout << sum;
    return 0;
}