#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
typedef long long int rt;

rt Longest_Unique_Characters_Substring(string str1){
    unordered_map<char, rt> map;
    rt start_index = -1, max_len = 0;
    for (rt i = 0; i < str1.length(); i++){
        // returns 1 if str[i] found in map
        if (map.count(str1[i])){
            start_index = max(start_index, map[str1[i]]);
           // cout<<start_index<<"  "<<map[str1[i]]<<"\n";
        }
            

        // max_len remains same or increments in every iteration.
        max_len = max(max_len, i - start_index);
        map[str1[i]] = i;
    }

    return max_len;
}

int main(){
    rt a;
    cin>>a;
    string str1;
    for(rt i=0;i<a;++i){
        cin>>str1;
        cout<<Longest_Unique_Characters_Substring(str1)<<"\n";
    }
    
}