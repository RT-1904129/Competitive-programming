#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


void diceRollHelper(string & choose,int N,int H){
    if(N==0){
        if(H!=count(choose.begin(), choose.end(),'1')) return;   
        cout<<choose<<" ";
        return;
    }
    else{
        for(int i=0 ;i<=1;++i){
            if(count(choose.begin(), choose.end(),'1')>H) return;
            if(count(choose.begin(), choose.end(),'1')+N <H) return;
            choose+=to_string(i);
            diceRollHelper(choose,N-1,H);
            choose.erase(choose.end()-1);
        }
    }
}

void Binary_Strings_with_same_Hamming_Distance(int & N,int & H){
    string str;
    diceRollHelper(str,N,H);
}

int main(){
    int test_cases, N, H, max, i, j;
    scanf("%d", &test_cases);
    while (test_cases--){
        scanf("%d %d", &N, &H);
        Binary_Strings_with_same_Hamming_Distance(N,H);
        if (test_cases)
            printf("\n");
    }
    return 0;
}