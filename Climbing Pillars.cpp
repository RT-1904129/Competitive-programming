#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int furthest_pillar(vector<int> &pillars, int bricks, int ladders)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < pillars.size() - 1; i++)
    {
        int climb = pillars[i + 1] - pillars[i];
        // if no need to climb
        if (climb <= 0)
            continue;

        // store climbs
        pq.push(climb);

        // allocate all ladders first
        if (pq.size() <= ladders)
            continue;

        // re-allocate smallest climb to bricks
        bricks -= pq.top();
        pq.pop();

        // if we run out of bricks
        if (bricks < 0)
            return i;
    }
    return pillars.size() - 1;
}

int main()
{
    int N, bricks, ladders;
    cin >> N >> bricks >> ladders;
    vector<int> pillars(N);
    for (int &itr : pillars)
    {
        cin >> itr;
    }

    cout << furthest_pillar(pillars, bricks, ladders);
    return 0;
}