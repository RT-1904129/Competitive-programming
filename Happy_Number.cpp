#include<iostream>
#include<unordered_set>
using namespace std;
typedef long long int rt;

rt Happy_Number(rt num){
    unordered_set<rt> sum_keys;
    rt sum;
    while (num != 1){
        sum = 0;
        // Find sum of the square of digits
        while (num > 0){
            sum += (num % 10) * (num % 10);
            num /= 10;
        }
        // Check if sum is already present in sum_keys
        if (sum_keys.find(sum) != sum_keys.end())  return 0;
        sum_keys.insert(sum);
        num = sum;
    }
    return 1;
}

int main(){
    rt a,b;
    cin>>a;
    for(rt i=0;i<a;++i){
        cin>>b;
        b=Happy_Number(b);
        if(b==1)
            cout<<"Happy Number"<<"\n";
        else cout<<"Not a Happy Number"<<"\n";
    }
}