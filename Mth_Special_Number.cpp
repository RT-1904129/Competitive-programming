#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

void diceRollHelper(int numDice,deque<string>& choose,string &str1,int postion){
    if(numDice==0){
        choose.push_back(str1);
    }
    else{
        for(int i=1 ;i<=3;++i){
            int j=str1[str1.length()-1]-'0';
            if(i==j) continue;
            if(choose.size()>=postion) return;
            str1+=to_string(i);
            diceRollHelper(numDice-1,choose,str1,postion);
            str1.erase(str1.end()-1);
        }
    }
}

void Mth_Special_Number(int numlength,int postion){
    string str1;
    deque<string>choose;
    diceRollHelper(numlength,choose,str1,postion);
    if(postion<=choose.size()) cout<<choose[postion-1];
    else cout<<-1;
}

int main(){
    string str;
    int N,M;
    cin>>N>>M;
    Mth_Special_Number(N,M);
    }