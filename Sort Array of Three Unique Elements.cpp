#include <iostream>
#include <climits>
using namespace std;

void sort_array(int arr[], int n)
{
    int min_val = INT_MAX, max_val = 0, mid_val;
    int min_count = 0, max_count = 0, mid_count = 0;

    for (int i = 0; i < n; i++)
    {
        max_val = max(max_val, arr[i]);
        min_val = min(min_val, arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == min_val)
            min_count++;
        else if (arr[i] == max_val)
            max_count++;
        else
        {
            mid_val = arr[i];
            mid_count++;
        }
    }

    int i = 0;
    for (i; i < min_count; i++)
        arr[i] = min_val;
    for (i; i < min_count + mid_count; i++)
        arr[i] = mid_val;
    for (i; i < min_count + mid_count + max_count; i++)
        arr[i] = max_val;

    return;
}

int main()
{
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort_array(arr, N);
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";

    return 0;
}