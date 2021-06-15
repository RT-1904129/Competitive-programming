#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int tests;
    ll K, no_of_operations;
    cin >> tests;
    //We are doing operations from value K to 0
    while (tests--){
        cin >> K;
        no_of_operations = 0L;
        while (K != 0L){
            if (K % 2L == 0L)
                K /= 2L;
            else{
                if ((((K - 1) / 2L) % 2L == 0L) || (K - 1 == 2))
                    K--;
                else
                    K++;
            }
            no_of_operations++;
        }
        cout << no_of_operations;
        if (tests > 0)
            cout << "\n";
    }
    return 0;
}