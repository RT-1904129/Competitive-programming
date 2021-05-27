#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;


void Matrix_Searching(vector<vector<long int>>&array,long int target,long int m,long int n){
    long int i=0,j=0,l=0,r=n-1;
    while((i<m)&&(array[i][j]<=target)) i++;
    if(i>0) i--;
    while (l <= r) {
        long int mid = l + (r - l) / 2;
        if (array[i][mid] == target){
            cout<<i<<" "<<mid;
            j=1;
            break;
        }
        if (array[i][mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    if(j==0) cout<< -1;
}

int main(){
    long int a,m,n,target;
    ios::sync_with_stdio(false);
    cin>>m>>n;
    vector<vector<long int>>array;
    for(long int i=0;i<m;++i){
        vector<long int>array1;
        for(long int j=0;j<n;++j){
            cin>>a;
            array1.push_back(a);
        }
        array.push_back(array1);
    }
    cin>>target;
    Matrix_Searching(array,target,m,n);  
}