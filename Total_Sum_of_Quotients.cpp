#include<iostream>
#include<algorithm>
#include <vector>
#include<climits>
using namespace std;
typedef long long int rt;
rt check(vector<rt>array,rt low,rt high,rt b){
    rt sum=0;
    for(rt i=low;i<=high;++i)  sum+=(array[i]/b) ;//Total Sum of Quotients
    return(sum);
}

rt Total_Sum_of_Quotients(vector<rt>array,rt low,rt high,rt constrained){
    rt max_value= *max_element(array.begin(),array.end());
    rt checki=max_value;
    rt low_value=1;
    rt mid=0;
    rt sum=0;
    while(low_value<=max_value){
        mid=(low_value+max_value)/2;
        sum=check(array,low,high,mid);
        if(sum>constrained) low_value=mid+1;
        else  {max_value=mid-1;checki=min(mid,checki);}
    }
    return checki;
}


int main(){
    rt a,b;
    cin>>a>>b;
    vector<rt>array(a);
    for(rt i=0;i<a;i++) cin>>array[i];
    rt count=Total_Sum_of_Quotients(array,0,a-1,b);
    cout<<count;
}