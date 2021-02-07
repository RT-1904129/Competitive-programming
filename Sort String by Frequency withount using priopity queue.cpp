/*
Authur-Rishabh Tripathi
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
typedef long long int rt;
struct line{
    char word;
    rt count;
};

bool compare(line a,line b){
    if(a.count==b.count) return(a.word>b.word);
    else return(a.count>b.count);
}

int main(){
    rt a;
    cin>>a;
    string str;
    for(rt i=0;i<a;++i){
        cin>>str;
        vector<line>array;
        rt len = str.length();
        // Find Frequency of every character
        rt char_frequency[26] = {0};
        for (rt i = 0; i < len; i++)
            char_frequency[str[i] - 'a']++;
        for (int i = 0; i < 26; i++){
            if (char_frequency[i] > 0){
                line temp;
                temp.word='a'+i;
                temp.count=char_frequency[i];
                array.push_back(temp);
            }}
        sort(array.begin(),array.end(),compare);
        for(rt i=0;i<array.size();++i){
            char c=array[i].word;
            for(rt j=0;j<array[i].count;++j) cout<<c;
        }
        cout<<"\n";
}}