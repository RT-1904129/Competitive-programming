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
            array[b][i]++;
            cin>>b;
        }
    }
    int sum=0,max=0,index=0;
    for(int i=0;i<a;++i){
        sum=0;
        for(int j=0;j<a;++j){
            sum+=array[i][j];
        }
        if(sum>max) {index=i; max=sum;}
    }
    cout<<index;
}