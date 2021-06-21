#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <deque>
using namespace std;

void Print(deque<string> &arr){
    for(int i=0;i<arr.size();++i) cout<<arr[i]<<"\n";
}

void diceRollHelper(int numDice,deque<string>& choose,string & str,string & str1,int start){
    if(numDice==0){
        choose.push_back(str1);
    }
    else{
        for(int i=start ;i< str.length();++i){
            str1+=str[i];
            diceRollHelper(numDice-1,choose,str,str1,i+1);
            str1.erase(str1.end()-1);
        }
    }
}

void N_Length_Combinations(string str,int numlength){
    string str1;
    deque<string>choose;
    diceRollHelper(numlength,choose,str,str1,0);
    set<string>arr2(choose.begin(),choose.end());
    choose.assign(arr2.begin(),arr2.end());
    Print(choose);
}

int main(){
    string str;
    int a;
    while(cin>>str){
        cin>>a;
        sort(str.begin(),str.end());
        N_Length_Combinations(str,a);
    }
}