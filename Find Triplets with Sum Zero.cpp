#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

void get_threesum(int nums[], int n){
    vector<vector<int>> triplets;
    set<pair<int, int>> unique_pairs;

    for (int i = 0; i < n; i++){
        unordered_set<int> seen;
        for (int j = i + 1; j < n; j++){
            int complement = -nums[i] - nums[j];
            // if triplet can be formed
            if (seen.count(complement)){
                // min and max values of the triplet
                int min_val = min(nums[i], min(complement, nums[j]));
                int max_val = max(nums[i], max(complement, nums[j]));

                //  push the pair to unique_pairs. returns 0 if pair already exists.
                if (unique_pairs.insert({min_val, max_val}).second)
                    triplets.push_back({nums[i], complement, nums[j]});
            }
            seen.insert(nums[j]);
        }
    }
    for (int i = 0; i < triplets.size(); i++)
        printf("%d %d %d\n", triplets[i][0], triplets[i][1], triplets[i][2]);

}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d ",&arr[i]);

    get_threesum(arr, n);
    return 0;
}