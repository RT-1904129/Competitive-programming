/*
Auther:Rishabh Tripathi
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    string input;
    cin>>input;
    int count=1,c,g;
    vector<char>array1(1);
    array1[0]=input[0];
    for(int i=1;i<input.length();++i){
        c=count;                //stack container problem
        g=0;
        for(int j=0;j<c;++j){
            if (array1[j]>=input[i]) {
                array1[j]=input[i];
                g=1;
                break;
            }
        }
        if(g==0){
            array1[count]=input[i];
            count++;
        }
    }
   cout<<count; 
}