#include<iostream>
#include<vector>
#include<climits>
using namespace std;

typedef unsigned long long int rt;
rt ispossible(vector<rt>array,rt mid){
    rt index=0;
    rt count =1;                    //Distribute Books to Students
    rt sum=0;
    while(index<array.size()){
        sum= sum+array[index];
        if(sum>mid){
            count++;
            sum=array[index];
    }
    index++;
  }
  return count;
  }
  
rt maxpages(vector<rt>array,rt books,rt stud){
    rt start=array[books-1];
    rt end=0;
    rt result=LLONG_MAX;
    if(books!=stud){
        for(rt i=0;i<books;i++)     end+=array[i];
        rt mid=0;
        while(start<=end){
            mid= (start+end)/2;
            rt check= ispossible(array,mid);
         if(check==stud){
           result=min(result,mid);
           end=mid-1;
            }
         else if(check>stud){
           start=mid+1;
            }
         else if(check<stud){
           end=mid-1;
            }}}
    else result=start;
   return result;
}

int main(){
  rt a,b;
  cin>>a>>b;
  vector<rt>array(a);
  for(rt i=0;i<a;i++) cin>>array[i];
  rt maxi= maxpages(array,a,b);
  cout<<maxi;
}