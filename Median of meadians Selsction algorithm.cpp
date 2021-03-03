#include <iostream>
#include <algorithm>
using namespace std;

// It searches for x in arr[l..r], and partitions the array around x
int partition(int arr[], int l, int r, int x)
{
    // Search for x in arr[l..r] and move it to end
    int i;
    for (i = l; i < r; i++)
        if (arr[i] == x)
            break;
    swap(arr[i], arr[r]);
    // Now move all the elements < x to the left side
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] < x)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

//Find Median of 5 elements
int find_median(int arr[], int n)
{
    sort(arr, arr + n);
    return arr[n / 2];
}

int kth_smallest_element(int arr[], int left, int right, int k)
{
    if (left == right)
        return arr[left];
    // num of elements in this segment of array
    int n = right - left + 1;

    // divide the array into groups of size 5 and store the medians of these groups in median array
    // There will be floor((n+4)/5) groups;
    int i, median[(n + 4) / 5];
    for (i = 0; i < n / 5; i++)
        median[i] = find_median(arr + left + i * 5, 5);
    //For last group with less than 5 elements
    if (i * 5 < n)
    {
        median[i] = find_median(arr + left + i * 5, n % 5);
        i++;
    }

    // Find median of all medians using recursive call.
    int med_of_med = kth_smallest_element(median, 0, i - 1, i / 2);

    // Partition the array around a median of median element and
    // get position of pivot element in sorted array
    int pos = partition(arr, left, right, med_of_med);

    // If position is same as k
    if (pos - left == k - 1)
        return arr[pos];
    // If position is more, recur for left
    if (pos - left > k - 1)
        return kth_smallest_element(arr, left, pos - 1, k);

    // Else recur for right subarray
    return kth_smallest_element(arr, pos + 1, right, k - pos + left - 1);
}

int main()
{
    int N, k;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cin >> k;
    cout << kth_smallest_element(arr, 0, N - 1, k);
    return 0;
}