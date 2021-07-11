#include <iostream>
#include <bitset>
#include <unordered_map>
#include <string>
using namespace std;
typedef unsigned long long int lli;
typedef long int li;
void set(lli *a,int b){
    *a |=(1<<b);
}
void un_set(lli * a,int b){
    *a &= ~(1<<b);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=0;
    cin>>t;
    while(t--){
        lli n,a=0,b=0,i=0;
        bool turn=true;
        cin>>n;
        bitset<32>arr(n);
        while(1ULL<< i<=n){
            if(n & (1ULL << i)&& turn) {
                    a |= 1ULL << i;
                    turn = !turn;
                }
            else if(n & (1ULL << i)&& !turn) {
                     b |= 1ULL << i;
                     turn = !turn;
                }
            i++;
        }
        cout<<a<<" "<<b<<"\n";
    }
    return 0;
}