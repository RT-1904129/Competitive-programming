#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
using namespace std;
typedef unsigned long long int ulli;
typedef long long int lli;
typedef long int li;





int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,t;
    cin>>n;
    vector<lli>arr(n+1);
    for(int i=0;i<n;++i){
        arr[i+1]=arr[i & (i+1)] + 1;
    }
    for(int i=0;i<=n;++i)  cout<<arr[i]<<" ";
    return 0;
}