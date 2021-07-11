#include <iostream>
#include <string.h>
#include <unordered_map>

using namespace std;
unordered_map<string, bool> valid;

bool isEmpty(string str){
    if (str.empty())
        return true;
    if (valid.count(str))
        return valid[str];
    int i = 0;
    bool isPossible = false;
    while (i < str.length() && !isPossible){
        int j = i;
        while (j + 1 < str.length() && str[j + 1] == str[i])
            j++;
        // if there is a sequence, recursively check if we can remove it
        if (j != i)
            isPossible = isEmpty(str.substr(0, i) + str.substr(j + 1));
        i = j + 1;
    }
    // stores if this substring leads to empty string or not
    valid[str] = isPossible;
    return isPossible;
}

int main(){
    int t;
    string str;
    cin >> t;
    while (t--)
    {
        cin >> str;
        valid.clear();
        if (isEmpty(str))
            cout << "True\n";
        else
            cout << "False\n";
    }
}