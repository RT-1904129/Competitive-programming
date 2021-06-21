#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

void diceRollHelper(deque<int>& choose,int N,int M,int sum,int start){
    if((sum<=M)&&(sum>=N)) {
        choose.push_back(sum);
    }
    for(int i=start;i<=9;++i){
        if(sum> M) return;
        if(i>start) return;
        sum=sum*10+i;
        diceRollHelper(choose,N,M,sum,i+1);
        sum=(sum-i)/10;
    }

}

void Sequential_Digits(int N,int M){
    deque<int>choose;
    int sum=0;
    for(int i=1;i<=9;++i)
        diceRollHelper(choose,N,M,sum,i);
    if(choose.size()==0) {
        cout<<0;
        return ;
    }
    sort(choose.begin(),choose.end());
    for(int i=0;i<choose.size();++i) cout<<choose[i]<<" ";
}

int main(){
    int N,M;
    cin>>N>>M;
    Sequential_Digits(N,M);
    }