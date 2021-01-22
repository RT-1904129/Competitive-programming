/*
Auther:Rishabh Tripathi
*/
#include<iostream>
#include<vector>
using namespace std;
int main(){
    //ios::sync_with_stdio(false);
    typedef long long int rt;
    vector<rt>array1(2);
    scanf("%lld %lld",&array1[0],&array1[1]);
    vector<rt>array3(array1[0]);
    rt count=0;
    for(rt i=1;i<array1[0]+1;++i){
        if(((array1[0]%i)==0)&&((array1[1]%i)==0)) {array3[count]=i; count++;}
    }
    rt a,max;
    scanf("%lld",&a);
    vector<rt>array2(2);            //Find GCD in Given Range
    for(rt i=0;i<a;++i){
        max=0;
        scanf("%lld %lld",&array2[0],&array2[1]);
        for(rt j=0;j<count;++j){
                if((array3[j]>=array2[0])&&(array3[j]<=array2[1])) {
                    if(max<array3[j]) max=array3[j];
                }
            }
        if(max==0) printf("-1\n");
        else printf("%lld\n",max);
    }}