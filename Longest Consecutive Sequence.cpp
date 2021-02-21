#include<iostream>
#include<set>
#include<vector>
using namespace std;

typedef long long int rt;
rt Longest_Consecutive_Sequence(vector<rt>arr){
    set<rt>arr1;
    for(rt i=0;i<arr.size();++i){
         arr1.insert(arr[i]);
    }
    rt count=0,max=0,diff=0;
    rt previous=*(arr1.begin());
    for(auto itr=arr1.begin();itr!=arr1.end();++itr){
        diff=(*itr)-previous;
        if((diff==1)||(diff==0)) count++;
        else {
            if(count>max) max=count;
            count=1;
        }
        previous=*(itr);
    }
    if(max<count) max=count;
    return max;
    
}


int main(){
    rt a,b,c;
    cin>>a;
    for(rt i=0;i<a;++i){
        cin>>b;
        vector<rt>arr2;
        for(rt j=0;j<b;++j){
            cin>>c;
            arr2.push_back(c);
        }
        c=Longest_Consecutive_Sequence(arr2);
        cout<<c<<"\n";
    }
}