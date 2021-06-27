#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long int lli;


lli Nth_Catalan_Number(int n){
    lli arr[n+1];
    for(int i=0;i<=n;++i){
        if(i==0) arr[i]=1;
        else{
            lli count=0;
            for(int j=0;j<=i-1;++j){
                count+=arr[j]*arr[i-j-1];
            }
            arr[i]=count;
        }
    }
    return arr[n];
}

int main(){
    int m, n;
    cin >> m ;
    cout << Nth_Catalan_Number(m);
    return 0;
}