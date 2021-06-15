#include <iostream>
#include<cmath>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long int rt;
void Happy_Number(rt &a){
    unordered_map<rt,rt>arr;
    while(a!=1){
        rt sum=0;
        while(a){
            sum+=pow(a%10,2);
            a=a/10;
        }
        if(arr.find(sum)!=arr.end()){
            cout<<"Not a Happy Number\n";
            return;
        }
        arr[sum]=1;
        a=sum;
    }
    cout<<"Happy Number\n";
}

int main(){
    rt t,a;
    scanf("%lld ", &t);
    for (rt i = 0; i < t; i++){
        scanf("%lld ",&a);
        Happy_Number(a);
    }
}