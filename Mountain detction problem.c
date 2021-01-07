#include <stdio.h>
//using namespace std;
int main(){
    //ios::sync_with_stdio(false);
    long long int a,count=0,check=0,max=0,mountain=0;
    scanf("%lld",&a);
    long long int b[a];
    for(int i=0;i<a;++i){
        scanf("%lld",&b[i]);
    }
    for(int i=0;i<a-1;++i){
        if(i!=0){
        if (b[i]<b[i+1]){
            if (b[i]<b[i-1]) {
                check=1; count++;}
            else if (check==1) count++;
        }
        else if (b[i]>b[i+1]){
            if (b[i+1]<b[i+2]){
                if(max<(count+2)) max=count+2;
                mountain++;
                count=0;
                check=0;
            }
            else count++;
        }
    }
    else {
        if (b[i]<b[i+1]){
            check=1; count++;}
        else count++;
        }
    }
if(max<(count)) max=count;
if(mountain!=0) printf("%lld",max);
else  printf("%lld",0);
}