#include <iostream>
#include <algorithm>
using namespace std;

void get_sequences_count(string str, int &result, int level){
    result++;
    for(int i = level; i < str.size(); i++){
        // skip duplicates
        if (i != level && str[i] == str[level])
            continue;
        swap(str[i], str[level]);
        get_sequences_count(str, result, level + 1);
    }
    return;
}

int main()
{
    string str;
    cin >> str;

    int result = -1;
    sort(str.begin(), str.end());
    get_sequences_count(str, result, 0);
    cout << result;
    return 0;
}