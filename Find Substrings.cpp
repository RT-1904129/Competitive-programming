#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

void find_and_print_substring_index(string str, vector<string> strings);

int main()
{
    string str, input;
    int N;
    cin >> str >> N;
    vector<string> strings;
    while (N--)
    {
        cin >> input;
        strings.push_back(input);
    }
    find_and_print_substring_index(str, strings);
}

void find_and_print_substring_index(string str, vector<string> words)
{

    int no_output = 1;
    if (str.size() < words[0].size() * words.size() || words.size() == 0)
    {
        cout << "-1";
        return;
    }

    unordered_map<string, int> mp, mp_temp;
    // store frequency of words
    for (int i = 0; i < words.size(); i++)
        mp[words[i]]++;

    int w = words[0].size();
    // loop over the indicies of the str starting from 0 till it is possible to form such substring.
    for (int i = 0; str.size() - i >= w * words.size(); i++)
    {
        if (mp.find(str.substr(i, w)) != mp.end())
        {
            mp_temp = mp;
            int j = i;
            string word = str.substr(j, w);

            while (mp_temp.find(word) != mp_temp.end())
            {
                if (mp_temp[word] == 1)
                    mp_temp.erase(word);
                else
                    mp_temp[word]--;
                j += w;
                //check if we can have one more word
                if (j + w - 1 < str.length())
                    word = str.substr(j, w);
                else
                    break;
            }

            if (mp_temp.empty())
            {
                cout << i << " ";
                no_output = 0;
            }
        }
    }

    if (no_output)
        cout << "-1";

    return;
}