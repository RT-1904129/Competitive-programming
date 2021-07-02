#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
typedef long long int lli;
typedef long int li;

bool Possibility_of_Divisibility(vector<int>&arr,int k,int size,int sum){
    if(size==0) {
        if((sum%k)==0) return true;
        else return false;
    }
    else
        return Possibility_of_Divisibility(arr,k,size-1,sum+arr[size-1]) || Possibility_of_Divisibility(arr,k,size-1,sum-arr[size-1]);
}




int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t,n,m,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int>arr(n);
        for(int i=0;i<n;++i){
            cin>>arr[i];
        }
        if(Possibility_of_Divisibility(arr,k,n-1,arr[n-1])) cout<<"True\n";
        else cout<<"False\n";
    }
    return 0;
}