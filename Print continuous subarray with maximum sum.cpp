#include <iostream>
using namespace std;
 //Time Complexity is O(n) two pointer method
 
// Function to print contiguous subarray with the largest sum
// in a given set of integers
void kadane(int arr[], int n)
{
    // stores maximum sum subarray found so far
    int max_so_far = 0;
 
    // stores the maximum sum of subarray ending at the current position
    int max_ending_here = 0;
 
    // stores endpoints of maximum sum subarray found so far
    int start = 0, end = 0;
 
    // stores starting index of a positive-sum sequence
    int beg = 0;
 
    // traverse the given array
    for (int i = 0; i < n; i++)
    {
        // update the maximum sum of subarray "ending" at index `i`
        max_ending_here = max_ending_here + arr[i];
 
        // if the maximum sum is negative, set it to 0
        if (max_ending_here < 0)
        {
            max_ending_here = 0;    // empty subarray
            beg = i + 1;
        }
 
        // update result if the current subarray sum is found to be greater
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = beg;
            end = i;
        }
    }
 
    cout << "The sum of contiguous subarray with the largest sum is " <<
            max_so_far << endl;
 
    cout << "The contiguous subarray with the largest sum is ";
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
}
 
int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int n = sizeof(arr)/sizeof(arr[0]);
 
    kadane(arr, n);
 
    return 0;
}