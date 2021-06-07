#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

double GetWage(vector<int> quality, vector<int> wage, int num_workers)
{
    int N = quality.size();
    vector<pair<double, int>> workers_profile;

    for (int i = 0; i < N; ++i)
        workers_profile.push_back({(double)wage[i] / quality[i], quality[i]});

    // Sorting in the increasing order of wage-to-quality ratio
    sort(workers_profile.begin(), workers_profile.end());

    // Max priority queue of qualities
    priority_queue<int> pq;
    // Sum of qualities
    int sum_qualities = 0;

    for (int i = 0; i < num_workers; ++i)
    {
        sum_qualities += workers_profile[i].second;
        pq.push(workers_profile[i].second);
    }

    double total_wage = sum_qualities * workers_profile[num_workers - 1].first;

    for (int i = num_workers; i < N; i++)
    {
        int max = pq.top();
        if (max > workers_profile[i].second)
        {
            pq.pop();
            pq.push(workers_profile[i].second);
            sum_qualities = sum_qualities + workers_profile[i].second - max;

            double ratio = workers_profile[i].first;
            total_wage = min(total_wage, sum_qualities * ratio);
        }
    }
    return total_wage;
}

int main()
{
    // Scanning the arrays of quality and minimum wage expectation
    vector<int> quality, wage;
    int temp, num_workers;

    while (cin >> temp)
    {
        if (temp == -1)
            break;
        quality.push_back(temp);
    }

    while (cin >> temp)
    {
        if (temp == -1)
            break;
        wage.push_back(temp);
    }

    // Number of workers to be selected
    cin >> num_workers;
    double total_wage = GetWage(quality, wage, num_workers);
    printf("%.3f", total_wage);
    return 0;
}