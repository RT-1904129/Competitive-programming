#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> get_twosum(int nums[], int n, long long int target)
{
    unordered_map<int, int> map;
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        if (map.find(target - nums[i]) != map.end())
        {

            result.push_back(map[target - nums[i]]);
            result.push_back(i);
            break;
        }
        else
            map[nums[i]] = i;
    }

    return result;
}

int main()
{
    int n;
    long long int k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> result = get_twosum(arr, n, k);
    cout << result[0] << " " << result[1];
    return 0;
}