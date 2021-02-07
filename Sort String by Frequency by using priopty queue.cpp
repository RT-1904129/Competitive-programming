/*
Authur-Rishabh Tripathi
*/
#include <iostream>
#include <queue>
using namespace std;

string sort_by_frequency(string str)
{
    string result = "";

    int char_frequency[26] = {0};
    for (char i : str)
        char_frequency[i - 97]++;

    priority_queue<pair<int, char>> pq;
    for (int i = 0; i < 26; i++)
        if (char_frequency[i] > 0)
            pq.push(pair<int, char>(char_frequency[i], i + 97));

    while (pq.size())
    {
        int freq = pq.top().first;
        char c = pq.top().second;
        while (freq--)
            result += c;
        pq.pop();
    }

    return result;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        string S;
        cin >> S;
        if (T > 0)
            cout << sort_by_frequency(S) << endl;
        else
            cout << sort_by_frequency(S);
    }

    return 0;
}