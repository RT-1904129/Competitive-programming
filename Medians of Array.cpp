#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void find_median(vector<int> &arr, int index)
{
    static priority_queue<int> small;
    static priority_queue<int, vector<int>, greater<int>> large;
    static int itr = 0;

    for (itr; itr <= index; itr++){
        small.push(arr[itr]);
        large.push(small.top());
        small.pop();
        if (small.size() < large.size()){
            small.push(large.top());
            large.pop();
        }
    }
    if (small.size() > large.size())
    {
        printf("%.2lf ", (double)small.top());
    }
    else
    {
        printf("%.2lf ", (small.top() + large.top()) / 2.0);
    }
    return;
}

void solve_queries(vector<int> &arr, vector<int> &queries)
{
    for (int i : queries)
    {
        find_median(arr, i);
    }
    return;
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    vector<int> queries(K);
    for (int &itr : arr)
    {
        cin >> itr;
    }
    for (int &itr : queries)
    {
        cin >> itr;
    }

    solve_queries(arr, queries);
    return 0;
}