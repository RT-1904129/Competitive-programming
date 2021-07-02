#include <iostream>
#include <climits>
#include <vector>
using namespace std;
#define MAX 20

vector<vector<bool>> isPalindrome(MAX, vector<bool>(MAX, 0));
void findPalindromes(string str)
{
    int n = str.length();
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
                isPalindrome[i][j] = true;
            else if (str[i] == str[j])
                isPalindrome[i][j] = ((j - i == 1) ? true : isPalindrome[i + 1][j - 1]);
            else
                isPalindrome[i][j] = false;
        }
    }
}

int minPalindromePartition(string str)
{
    int n = str.length();

    vector<int> lookup(n);

    for (int i = n - 1; i >= 0; i--)
    {
        lookup[i] = INT_MAX;
        // if str[i,..,n-1] is a palindrome, total cuts needed is 0
        if (isPalindrome[i][n - 1])
            lookup[i] = 0;
        else{
            for (int j = n - 2; j >= i; j--)
                if (isPalindrome[i][j])
                    lookup[i] = min(lookup[i], 1 + lookup[j + 1]);
        }
    }

    return lookup[0];
}

int main()
{
    string str;
    cin >> str;
    findPalindromes(str);

    cout << minPalindromePartition(str);

    return 0;
}