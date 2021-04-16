#include<iostream>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a;
    int array[a][a];
    for(int i=0;i<a;++i){
        for(int j=0;j<a;++j){
            array[i][j]=0;
        }
    }
    for(int i=0;i<a;++i){
        int j=0;
        cin>>b;
        while(b!=-1){
            array[i][b]++;
            cin>>b;
        }
    }
    int sum1=0,sum2=0,max=0,index=0;
    for(int i=0;i<a;++i){
        sum1=0;sum2=0;
        for(int j=0;j<a;++j){
            sum1+=array[i][j];
            sum2+=array[j][i];
        }
        if((sum1-sum2)>max) {index=i; max=sum1-sum2;}
    }
    cout<<index;
}