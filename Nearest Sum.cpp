#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
typedef long long int rt;
rt Nearest_Sum(vector<rt>&array){
    rt low=0,high=array.size()-1;
    rt clowest_sum=abs(array[low]+array[high]);
    while(low<high){
        rt sum=array[low]+array[high];
        if(clowest_sum>abs(sum)) clowest_sum=abs(sum);
        if(sum>0) high--;
        else if(sum<0) low++;
        else break;
    }
    return clowest_sum ;
}

void print_minimum_sum_array(vector<rt>&array,rt clowest_sum){
    rt low=0,high=array.size()-1;
    while(low<high){
        rt sum=array[low]+array[high];
        if(clowest_sum==abs(sum)) {
            cout<<array[low]<<" "<<array[high]<<"\n";
        }
        if(sum>0) high--;
        else if(sum<0) low++;
    }
}
int main(){
    rt a,n;
    ios::sync_with_stdio(false);
    cin>>n;
    vector<rt>array;
    for(rt i=0;i<n;++i){
        cin>>a;
        array.push_back(a);
    }
    sort(array.begin(),array.end());
    rt clowest_sum=Nearest_Sum(array);
    print_minimum_sum_array(array,clowest_sum);
}