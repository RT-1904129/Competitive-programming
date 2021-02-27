#include <iostream>
#include <algorithm>
using namespace std;

long long int get_possible_ways(int arr[], int n)
{
    int max = *max_element(arr, arr + n);
    int count[max + 1] = {0}, unique = 0;

    for (int i = 0; i < n; i++)
    {
        if (count[arr[i]] == 0)
            unique++;
        count[arr[i]]++;
    }

    return ((long long)unique * (unique - 1)) / 2;
}

int main()
{
    int T, N;
    cin >> T;

    while (T--)
    {
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        cout << get_possible_ways(arr, N) << endl;
    }

    return 0;
}