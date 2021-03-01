#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucket_sort(vector<double> &arr, int n)
{
    // add elements into buckets
    vector<double> buckets[n];
    for (int i = 0; i < n; i++)
    {
        int ind = n * arr[i] / 1000000000;
        buckets[ind].push_back(arr[i]);
    }

    // sort buckets. STL sort uses insertion sort if elements to sort are few.
    for (int i = 0; i < n; i++)
        sort(buckets[i].begin(), buckets[i].end());

    // concatenate all buckets
    int index = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < buckets[i].size(); j++)
            arr[++index] = buckets[i][j];

    return;
}

void sort_array(double arr[], int n)
{
    vector<double> negative_values, positive_values;

    for (int i = 0; i < n; i++)
        if (arr[i] > 0)
            positive_values.push_back(arr[i]);
        else
            negative_values.push_back(-arr[i]);

    bucket_sort(negative_values, negative_values.size());
    bucket_sort(positive_values, positive_values.size());

    // Replace A with negative values first and then positive values
    for (int i = 0; i < negative_values.size(); i++)
        arr[i] = -negative_values[negative_values.size() - 1 - i];
    for (int j = negative_values.size(); j < n; j++)
        arr[j] = positive_values[j - negative_values.size()];

    return;
}

int main()
{
    int N;
    cin >> N;
    double arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort_array(arr, N);
    for (int i = 0; i < N; i++)
        printf("%.2f ", arr[i]);

    return 0;
}