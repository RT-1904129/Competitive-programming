#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
typedef long long int rt;

rt Total_Number_of_Subarrays_Divisible_by_K(vector<rt>arr,rt k){
    rt curr_sum = 0;
    rt count = 0;
    unordered_map<rt,rt> map;
    for(int i=0;i<arr.size();i++){
        curr_sum += arr[i];
        if((curr_sum % k+k)%k == 0){
            count += 1;
        }
        if(map.find((curr_sum % k+k)%k) != map.end()){
            count += map[(curr_sum % k+k)%k];
        }
        map[(curr_sum % k+k)%k]++;
    }
    return count;
}

int main(){
    rt a,b,c,d;
    cin>>a;
    for(rt i=0;i<a;++i){
        vector<rt>arr;
        cin>>b>>c;
        for(rt j=0;j<b;++j){
            cin>>d;
            arr.push_back(d);
        }
        cout<<Total_Number_of_Subarrays_Divisible_by_K(arr,c)<<"\n";
    }
}