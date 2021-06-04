#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef  long int rt;

rt Maximum_Player_Level(vector<rt>&array,rt & health_level,rt &storege){
    rt count=1,n=array.size();
    priority_queue<rt,vector<rt>,greater<rt>>array1;
    for(rt i=1;i<n;++i){
        if((array[i]>array[i-1])&&(storege!=0)){
            if(array1.size()!=storege){
                array1.push(array[i]-array[i-1]);
            }
            else{
                health_level-=array1.top();
                array1.pop();
                array1.push(array[i]-array[i-1]);
            }
        }
        else if(storege==0){
            if(array[i]>array[i-1]) health_level-=(array[i]-array[i-1]);
        }
        if(health_level<0) break;
        count++;
    }
    return count;
}

int main(){
    rt a,x,n,y;
    ios::sync_with_stdio(false);
    cin>>n>>x>>y;
    vector<rt>array;
    for(rt i=0;i<n;++i){
        cin>>a;
        array.push_back(a);
    }
    cout<<Maximum_Player_Level(array,x,y);
}