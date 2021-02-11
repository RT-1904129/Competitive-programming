#include <iostream>
#include <deque>
#include <string>
using namespace std;

bool check_palindrome(string str)
{
    bool is_palindrome = true;
    int len = str.length();

    deque<char> dq;
    for (int i = 0; i < len; i++)
    {
        dq.push_back(str[i]);
    }

    while (dq.size() > 1 && is_palindrome)
    {
        char first = dq.front();
        dq.pop_front();
        char last = dq.back();
        dq.pop_back();

        if (first != last)
            is_palindrome = false;
    }
    return is_palindrome;
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
            cout << check_palindrome(S) << endl;
        else
            cout << check_palindrome(S);
    }
    return 0;
}