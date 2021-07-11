#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;


int next_lowest(int number)
{
    int m=0,n=0;
    for(int i=0;i<32;i++)
    {
        if(!(number&(1<<i)))
           n++;
        else
           break;
    }
    for(int j=n;j<32;j++)
    {
        if(number&(1<<j))
           m++;
        else
           break;
    }
    return number+pow(2,n)+pow(2,m-1)-1; 
}
int prev_highest(int number)
{
    int m=0,n=0;
    for(int i=0;i<32;i++)
    {
        if(!(number&(1<<i)))
           n++;
        else
           break;
    }
    
    for(int j=n;j<32;j++){
        if(number&(1<<j))
           m++;
        else
           break;
    }
    
    if(n!=0){
        return number-pow(2,n)+pow(2,n-1);
    }
    
    else{
        for(int j=m;j<32;j++){
            if(number&(1<<j))
               return (number-pow(2,m)-pow(2,j+1-m-2)+1);
        }
        return -1;
    }
}

int main()
{
    int n;
    cin>>n;
    cout<<prev_highest(n)<<" "<<next_lowest(n);
}