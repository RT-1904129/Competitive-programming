#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    typedef long long int rt;
    rt a,count=0,check=0;
    cin>>a;
    vector<rt>array1(a);
    for(rt i=0;i<a;++i) cin>>array1[i];
    for(rt i=0;i<a;++i){
        if(i==0){
            for(rt j=0;j<a;++j,check++){
                if(array1[i]>array1[j]) break;
            }
            if(check==a) count++;
            check=0;
        }
        else if(i==a-1){
            for(rt j=0;j<a;++j,check++){
                if(array1[i]<array1[j]) break;
            }
            if(check==a) count++;
            check=0;
        }
        else {
           for(rt j=0;j<=i;++j,check++){
               if(array1[i]<array1[j]) break;
           } 
           for(rt j=i+1;j<a;++j,check++){
               if(array1[i]>array1[j]) break;
           }
           if(check==a) count++;
           check=0;
        }
    }
  cout<<count;  
}