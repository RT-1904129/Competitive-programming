#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int get_max_loot(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited)

{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j] || grid[i][j] == 0)
        return 0;

    visited[i][j] = true;
    int up = get_max_loot(grid, i - 1, j, visited);
    int down = get_max_loot(grid, i + 1, j, visited);
    int right = get_max_loot(grid, i, j + 1, visited);
    int left = get_max_loot(grid, i, j - 1, visited);
    visited[i][j] = false;

    return grid[i][j] + max(up, max(down, max(right, left)));
}

int getMaximumGold(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int ans = INT_MIN;
    int x = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                x++;
            }
        }
    }
    if (x == m * n)
        return 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] != 0)
            {
                ans = max(ans, get_max_loot(grid, i, j, visited));
            }
        }
    }
    return ans;
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }
    cout << getMaximumGold(grid);
    return 0;
}