#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
typedef long int rt;

rt Minimize_Difference(vector<rt>&arr,int & N){
    rt min_value=INT_MAX;
    priority_queue<rt>array;
    for(rt i=0;i<N;++i){
        if(arr[i]%2!=0)  arr[i] *=2;
        if(arr[i]<min_value)  min_value=arr[i];
        array.push(arr[i]);
    }
    rt max_value=array.top(),result=max_value-min_value;
    while(max_value%2==0){
        array.pop();
        array.push(max_value/2);
        if(min_value>(max_value/2)) min_value=max_value/2;
        result=min(result,array.top()-min_value);
        max_value=array.top();
    }
    return result;
}

int main(){
    int N;
    cin >> N;
    vector<rt> arr(N);
    for (rt &itr : arr){
        cin >> itr;
    }
    cout<<Minimize_Difference(arr,N);
}