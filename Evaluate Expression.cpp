#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int get_maximum_value(vector<int> &A, int n)
{
    // initialize four lookup tables
    vector<int> first(n + 1, INT_MIN), second(n, INT_MIN);
    vector<int> third(n - 1, INT_MIN), fourth(n - 2, INT_MIN);

    // store maximum value of A[n] in decreasing order in first[]
    for (int i = n - 1; i >= 0; i--)
        first[i] = max(first[i + 1], A[i]);

    // store maximum value of A[n]-A[m] in decreasing order in second[]
    for (int i = n - 2; i >= 0; i--)
        second[i] = max(second[i + 1], first[i + 1] - A[i]);

    // store maximum value of A[n]-A[m]+A[j] in decreasing order in third[]
    for (int i = n - 3; i >= 0; i--)
        third[i] = max(third[i + 1], second[i + 1] + A[i]);

    // store maximum value of A[n]-A[m]+A[j]-A[i] in decreasing order in fourth[]
    for (int i = n - 4; i >= 0; i--)
        fourth[i] = max(fourth[i + 1], third[i + 1] - A[i]);

    return fourth[0];
}

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cout << get_maximum_value(arr, N);
    return 0;
}