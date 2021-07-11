#include <iostream>
using namespace std;

int main()
{
    int T, N, K;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N >> K;
        int mask = (1 << N) - 1;
        if ((mask & K) == mask)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}