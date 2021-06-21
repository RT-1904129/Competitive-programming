#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct event
{
    int start, end;
};

bool compare(event &e1, event &e2)
{
    if (e1.end == e2.end)
    {
        return e1.start < e2.start;
    }
    return e1.end < e2.end;
}

int main()
{
    int N, K, result = 0;
    cin >> N >> K;

    event events[N];
    for (int i = 0; i < N; i++)
    {
        cin >> events[i].start >> events[i].end;
    }
    sort(events, events + N, compare);

    multiset<int> end_times;
    for (int i = 0; i < N; i++)
    {
        auto it = end_times.lower_bound(-events[i].start);

        // If it starts before all end times
        if (it == end_times.end())
        {

            // If more classrooms, add
            if (end_times.size() < K)
            {
                end_times.insert(-events[i].end - 1);
                result++;
            }
            continue;
        }

        // Remove one that ends right before this and add this
        end_times.erase(it);
        end_times.insert(-events[i].end - 1);
        result++;
    }

    cout << result;
    return 0;
}