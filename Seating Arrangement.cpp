#include<iostream>
#include<string>
#include<utility>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef  long int rt;
void Seating_Arrangement(vector<pair<rt,rt>>&array,string &str){
    pair<rt,rt> boy,girl;
    vector<rt>sheet;
    priority_queue<pair<rt,rt>,vector<pair<rt,rt>>,greater<pair<rt,rt>>>array1{array.begin(),array.end()};
    priority_queue<pair<rt,rt>>arr;
    for(rt i=0;i<str.length();++i){
        if(str[i]=='0'){
            boy=array1.top();
            array1.pop();
            sheet.push_back(boy.second);
            arr.push(boy);
        }
        else{
            girl=arr.top();
            sheet.push_back(girl.second);
            arr.pop();
        }
    }
    for(rt i=0;i<sheet.size();++i){
        cout<<sheet[i]<<" ";
    }
}


int main(){
    rt a,m,n,k,t;
    string str;
    ios::sync_with_stdio(false);
    cin>>t;
    vector<pair<rt,rt>>array;
    for(rt i=0;i<t;++i){
        cin>>a;
        array.push_back({a,i+1});
    }
    cin>>str;
    Seating_Arrangement(array,str);
}