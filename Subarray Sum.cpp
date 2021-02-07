#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int rt;
 bool isLower(rt a,rt b){
     return(a<b);
 }

int main(){
    rt a,b,c,sum=0;
    cin>>a>>b>>c;
    rt array[a];
    for(rt i=0;i<a;++i) cin>>array[i];
    partial_sort(array,array+c,array+a,isLower);
    for(rt i=b-1;i<c;++i){
        sum+=array[i];
    }
    cout<<sum;
}