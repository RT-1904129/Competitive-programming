#include <iostream>
#include <vector>
using namespace std;

int minimum_cost(string s1, string s2){
    int n=s1.length(),m=s2.length();
    vector<vector<int>> arr3(n + 1, vector<int>(m + 1));
    for(int i=1;i<n+1;++i) arr3[i][0]=arr3[i-1][0]+(int)s1[i-1];
    for(int j=1;j<m+1;++j) arr3[0][j]=arr3[0][j-1]+(int)s2[j-1];
    for(int i=1;i<n+1;++i){
        for(int j=1;j<m+1;++j){
            if(s1[i-1]==s2[j-1]) arr3[i][j]= arr3[i-1][j-1];
            else
                arr3[i][j]=min((int)s1[i-1]+arr3[i-1][j],arr3[i][j-1]+(int)s2[j-1]);
        }
    }
    return arr3[n][m];
}

int main(){
    string S1, S2;
    cin >> S1 >> S2;

    cout << minimum_cost(S1, S2);
    return 0;
}