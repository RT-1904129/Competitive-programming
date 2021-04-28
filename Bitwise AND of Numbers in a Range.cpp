#include <iostream>
using namespace std;

typedef long long int lli;

lli range_bitwise_and(lli m, lli n)
{
    while (m < n)
    {
        n -= (n & -n);
        // cout<<n<<"\n";
    }
    return n;
}

int main()
{
    lli m, n;
    cin >> m >> n;
    cout << range_bitwise_and(m, n);
    return 0;
}