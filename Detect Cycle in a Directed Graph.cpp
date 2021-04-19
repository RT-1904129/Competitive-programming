#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int source, int destination)
{
    adj[source].push_back(destination);
    return;
}

bool check_cycle(int vertex, vector<int> graph[], vector<bool> &visited, vector<bool> &recursion_stack)
{
    visited[vertex] = true;
    recursion_stack[vertex] = true;

    for (auto i : graph[vertex])
    {
        // there is possible that this node not visited but cycle exit
        if (!visited[i] && check_cycle(i, graph, visited, recursion_stack))
        {
            return true;
        }
        // if that node  already present in recursive step its means there is cycle by knowing back edge present 
        else if (recursion_stack[i])
            return true;
    }
    recursion_stack[vertex] = false;
    return false;
}

string check_cycle(vector<int> graph[], int len)
{
    vector<bool> visited(len, false);
    // keep tracking of back edge
    vector<bool> recursion_stack(len, false);

    for (int i = 1; i < len; i++)
    {
        if (check_cycle(i, graph, visited, recursion_stack))
        {
            return "Yes";
        }
    }
    return "No";
}

int main()
{
    int n, source, destination;
    cin >> n;

    vector<int> graph[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> source;
        while (1)
        {
            cin >> destination;
            if (destination == -1)
                break;
            addEdge(graph, source, destination);
        }
    }

    cout << check_cycle(graph, n + 1);
    return 0;
}