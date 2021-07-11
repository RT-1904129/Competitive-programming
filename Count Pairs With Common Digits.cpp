#include <iostream>
#include <unordered_map>
using namespace std;

void get_mask_frequencies(int arr[], int n, unordered_map<int, int> &mask_freq)
{
    int curr_num, curr_num_mask;
    for (int i = 0; i < n; i++)
    {
        curr_num = arr[i];
        curr_num_mask = 0;

        while (curr_num > 0)
        {
            curr_num_mask = curr_num_mask | (1 << (curr_num % 10));
            curr_num /= 10;
        }

        mask_freq[curr_num_mask]++;
    }
}

long long int count_pairs_with_common_digits(int arr[], int n)
{
    unordered_map<int, int> mask_freq;
    get_mask_frequencies(arr, n, mask_freq);

    long long int num_of_pairs = 0;
    for (int i = 0; i < 1024; i++)
    {
        num_of_pairs += (mask_freq[i] * (mask_freq[i] - 1)) / 2;
        for (int j = i + 1; j < 1024; j++)
        {
            if (i & j)
                num_of_pairs += (mask_freq[i] * mask_freq[j]);
        }
    }
    return num_of_pairs;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << count_pairs_with_common_digits(arr, n);
    return 0;
}