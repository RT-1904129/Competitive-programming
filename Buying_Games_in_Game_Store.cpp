#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;
typedef long long int rt;
void diceRollHelper(deque<rt>& choose,deque<int> &str1,rt sum,int start){
    if(sum>=200){
        choose.push_back(sum);
    }
    for(int i=start;i<str1.size();++i){
        sum+=str1[i];
        diceRollHelper(choose,str1,sum,i+1);
        sum-=str1[i];
    }
    return;
}

void Buying_Games_in_Game_Store(deque<int>& str1,int size){
    rt sum=0;
    deque<rt>choose;
    diceRollHelper(choose,str1,sum,0);
    for(int i=0;i<choose.size();++i) sum+=choose[i];
    cout<<sum;
}

int main(){
    int N,M,a;
    cin>>N;
    deque<int>arr;
    for(int i=0;i<N;++i){
        cin>>a;
        arr.push_back(a);
    }
    Buying_Games_in_Game_Store(arr,N);
}