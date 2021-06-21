#include <iostream>
#include <deque>
using namespace std;

void Print(deque<int> &arr){
    cout<<"{ ";
    for(int i=0;i<arr.size();++i) cout<<arr[i]<<" ";
    cout<<" }\n";
}

void diceRollHelper(int numDice,deque<int>& choose){
    if(numDice==0){
        Print(choose);
    }
    else{
        for(int i=1 ;i<=6;++i){
            choose.push_back(i);
            diceRollHelper(numDice-1,choose);
            choose.pop_back();
        }
    }
}

void diceRoll(int numDice){
    deque<int>choose;
    diceRollHelper(numDice,choose);
}

int main(){
    diceRoll(3);
}