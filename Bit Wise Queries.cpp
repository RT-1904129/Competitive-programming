#include <iostream>
#include <bitset>
#include <unordered_map>
#include <string>
using namespace std;
typedef long long int lli;
typedef long int li;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,a,b;
    string str;
    bitset<32>arr;
    unordered_map<int ,bool>check;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>str;
        if(str=="CLR" ||str=="SET" ){
            cin>>a;
            if(str=="SET") arr.set(a);
            if(str=="CLR") arr.reset(a);
            check[a]=true;
        }
        else if(str=="OR"){
            cin>>a>>b;
            if(check[b] && check[a]){
                arr[a]=arr[a] | arr[b];
            }
            else if(check[b] || check[a]) {
                if((arr[b]==1)&& check[b]){
                    arr[a]=1;
                    check[a]=true;
                }
                else if((arr[a]==0)&& check[a]) check[a]=false;
            }
            else check[a]=false;
        }
        else if(str=="AND"){
            cin>>a>>b;
            if(check[b] && check[a]){
                arr[a]=arr[a] & arr[b];
            }
            else if(check[b] || check[a]) {
                if((arr[b]==0)&& check[b]){
                    arr[a]=0;
                    check[a]=true;
                }
                else if((arr[a]==1)&& check[a]) check[a]=false;
            }
            else check[a]=false;
        }
    }
    for(int i=31;i>=0;i--){
        if(check[i]) cout<<arr[i];
        else cout<<'#';
    }
    return 0;
}