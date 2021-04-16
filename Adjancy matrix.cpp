#include<iostream>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b;
    int array[a][a];
    for(int i=0;i<a;++i){
        for(int j=0;j<a;++j){
            array[i][j]=0;
        }
    }
    for(int i=0;i<b;++i){
      cin>>c>>d;
      array[c][d]=1;
      array[d][c]=1;
    }
    for(int i=0;i<a;++i){
        for(int j=0;j<a;++j){
            cout<<array[i][j]<<" ";
        }
        cout<<"\n";
    }
}