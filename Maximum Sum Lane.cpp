#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int rt;
int main(){
    rt a,b,sum1=0,sum2=0,c,d;
    ios::sync_with_stdio(false);
    cin>>a>>b;
    vector<rt>array1(a);
    vector<rt>array2(b);
    for(rt i=0;i<a;++i){
        cin>>array1[i];
    }
    for(rt i=0;i<b;++i){
        cin>>array2[i];
    }
    c=min(a,b);
    rt i=0;
    while(c){
        while(--c){
            if(array2[i]==array1[i]){
                sum2=max(sum2,sum1);
                sum1=sum2;
                sum2+=array2[i];
                sum1+=array1[i];
                ++i;
                break;
            }
            sum2+=array2[i];
            sum1+=array1[i];
            ++i;
        }
        
    }
    sum2+=array2[i];
    sum1+=array1[i];
    ++i;
    if(a>b){
        for(rt j=i;j<a;++j){
            sum1+=array1[j];
        }
        cout<<max(sum1,sum2);
    }
    else{
        // cout<<i;
        for(rt j=i;j<b;++j){
            sum2+=array2[j];
            // cout<<"ram";
        }
        cout<<max(sum1,sum2);
    }
}