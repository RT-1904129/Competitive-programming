#include <iostream>
#include <vector>
using namespace std;

bool word_break_dp(string &s, vector<string> &word_dict)
{
    size_t n = s.size();
    vector<bool> dp(n + 1, false);
    dp[n] = true;

    // Calculate dp values starting from dp[n-1] from the back of the string.
    for (int i = n - 1; i >= 0; --i){
        int max_len = n - i;
        for (string &w : word_dict){
            if (w.size() <= max_len){
                if(w == s.substr(i, w.size())){
                    //if the word w matches with the substring in 's' from index i
                    dp[i] = dp[i + w.size()];
                    if (dp[i])
                        break;
                }
            }
        }
    }
    return dp[0];
}

int main()
{
    int N, T;
    string s, input;
    vector<string> word_dict;
    cin >> N;
    while (N--)
    {
        cin >> input;
        word_dict.push_back(input);
    }
    cin >> T;
    while (T--)
    {
        cin >> s;
        if (word_break_dp(s, word_dict))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}