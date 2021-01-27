/*
Author:-Rishabh Tripathi
Gernally calculating power of x to n power have worst Time complexity is O(n)
But by Divide and Conquer method worst time Complexity is O(log(n))
*/
#include <iostream>
using namespace std;
typedef long long int rt;
rt Calculate_power(rt number,rt power){
    if(power==1) return number;
    rt value=Calculate_power(number,power/2);
    if((power%2)==0) return value*value;
    else return number*value*value;
}
int main() {
    rt power,number;
    cin>>number>>power;
    cout<<Calculate_power(number,power);
    return 0;
}