#include <iostream>
#include <unordered_map>
using namespace std;

int find_repeated_sequences(string s)
{
    int result = 0;
    unordered_map<char, int> aux_map;
    unordered_map<int, int> map;
    aux_map['A'] = 0;
    aux_map['C'] = 1;
    aux_map['G'] = 2;
    aux_map['T'] = 3;
    int n = s.size(), mask = 0, bitmask = (1 << 20) - 1;

    if (n == 0)
        return result;

    for (int i = 0; i < 10; i++)
    {
        mask = (mask << 2) | aux_map[(s[i])];
    }
    map[mask]++;

    for (int i = 10; i < n; i++)
    {
        mask = ((mask << 2) & bitmask) | aux_map[(s[i])];
        if (map.find(mask) != map.end() && map[mask] == 1)
            result++;
        map[mask]++;
    }

    return result;
}

int main()
{
    string str;
    cin >> str;

    cout << find_repeated_sequences(str);
    return 0;
}