#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long int ulli;

ulli count(ulli n){
    if (n == 0 || n == 1 || n == 2)
        return n;
    vector<ulli> tiles(n + 1);
    tiles[0] = 0;
    tiles[1] = 1;
    tiles[2] = 2;
    for (ulli i = 3; i <= n; i++){
        tiles[i] = tiles[i - 1] + tiles[i - 2];
    }
    return tiles[n];
}

int main(){
    ulli n;
    cin >> n;
    cout << count(n);
    return 0;
}