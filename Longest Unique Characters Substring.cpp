#include <iostream>
#include <unordered_map>
using namespace std;

int get_substring(string str)
{
    unordered_map<char, int> map;
    int start_index = -1, max_len = 0;

    for (int i = 0; i < str.length(); i++)
    {
        // returns 1 if str[i] found in map
        if (map.count(str[i]))
            start_index = max(start_index, map[str[i]]);

        // max_len remains same or increments in every iteration.
        max_len = max(max_len, i - start_index);
        map[str[i]] = i;
    }

    return max_len;
}

int main()
{
    int T;
    cin >> T;

    string str;
    while (T--)
    {
        cin >> str;
        cout << get_substring(str) << endl;
    }

    return 0;
}