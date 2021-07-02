#include <iostream>
#include <math.h>
#define MAX_NUMBERS 10000
#define MAX_DIVISOR 100
int num[MAX_NUMBERS];
int rem[MAX_NUMBERS][MAX_DIVISOR];
using namespace std;

int is_divisible(int n, int k){
    int i, j;

    rem[0][num[0] % k] = 1;
    for (i = 1; i < n; i++)
        for (j = 0; j < k; j++)
            if (rem[i - 1][j]){
                rem[i][(((j + num[i]) % k) + k) % k] = 1;
                rem[i][(((j + k - num[i]) % k) + k) % k] = 1;
            }

    return rem[n - 1][0];
}

int main(){

    int t;
    cin >> t;

    while (t--){
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < k; j++)
                rem[i][j] = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
            num[i] = abs(num[i]);
        }

        if (is_divisible(n, k))
            printf("True\n");
        else
            printf("False\n");
    }
    return 0;
}