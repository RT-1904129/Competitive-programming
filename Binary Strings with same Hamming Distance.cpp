#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void Binary_Strings_with_same_Hamming_Distance(int & N,int & H){
    int a=N;
    deque<int>arr;
    while(N--){
        if(H) {
            arr.push_back('1');
            H--;
        }
        else arr.push_front('0');
    }
    do{
        string str;
        for(int i=0;i<a;++i) str+=arr[i];
        cout<<str<<" ";
    }while(next_permutation(arr.begin(),arr.end()));
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