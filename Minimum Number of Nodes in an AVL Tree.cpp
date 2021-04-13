#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull get_minimum_nodes(int &h, ull base = 0, ull result = 1){
    if (h == 0)
        return result;

    return get_minimum_nodes(--h, result, base + result + 1);
}

int main()
{
    int h;
    cin >> h;
    if (h == 0){
        cout << 1;
    }
    else{
        cout << get_minimum_nodes(h);
    }
    return 0;
}