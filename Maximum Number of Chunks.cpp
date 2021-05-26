#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int Maximum_Number_of_Chunks(vector<int>&array){
    int maximum=0,count=0;
    for(int i=0;i<array.size();++i){
        maximum=max(maximum,array[i]);
        if(maximum==i) count++;
    }
    return count;
}


int main() {
    int a,b;
    ios::sync_with_stdio(false);
    cin>>a;
    vector<int>array;
    for(int i=0;i<a;++i){
        cin>>b;
        array.push_back(b);
    }
    cout<<Maximum_Number_of_Chunks(array);
    return 0;
}