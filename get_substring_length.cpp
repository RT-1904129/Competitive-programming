#include <iostream>
#include <unordered_map>
using namespace std;

int get_substring_length(string str, int k)
{
    int start = 0, len = 0;

    unordered_map<char, int> window;
    for (int end = 0; end < str.size(); end++)
    {
        window[str[end]]++;

        // move the window if it has K+1 unique characters
        while (window.size() == k + 1)
        {
            window[str[start]]--;
            if (window[str[start]] == 0)
                window.erase(str[start]);
            start++;
        }

        len = max(len, end - start + 1);
    }

    return len;
}

int main()
{
    int T, K;
    string str;
    cin >> T;
    while (T--)
    {
        cin >> K >> str;
        cout << get_substring_length(str, K) << endl;
    }
}