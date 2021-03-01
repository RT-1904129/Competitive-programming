#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bucketSort(double arr[], int n)
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

int main()
{
    int N;
    cin >> N;
    double arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    bucketSort(arr, N);

    for (int i = 0; i < N; i++)
        printf("%.2f ", arr[i]);
    return 0;
}