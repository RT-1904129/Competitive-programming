#include <iostream>
using namespace std;

int main()
{
    int N, person_1, person_2;
    cin >> N;

    int outdegrees[N + 1] ={ 0 }, indegrees[N + 1] ={ 0 };
    while (1)
    {
        cin >> person_1;
        if (person_1 == -1)
            break;
        cin >> person_2;

        outdegrees[person_1]++;
        indegrees[person_2]++;
    }

    for (int i = 1; i <= N; i++)
    {
        if (indegrees[i] == N - 1 && outdegrees[i] == 0)
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}