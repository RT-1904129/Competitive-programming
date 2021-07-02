#include <vector>
#include <iostream>
using namespace std;

long long int getMaxLoot(vector<vector<int>> &loot, int m, int n)
{
    vector<vector<long long int>> table(m, vector<long long int>(n, 0));

    for (int col = n - 1; col >= 0; col--)
    {
        for (int row = 0; row < m; row++)
        {
            //right(->)
            long long int right = (col == n - 1) ? 0 : table[row][col + 1];

            //right up (/)
            long long int right_up = (row == 0 || col == n - 1) ? 0 : table[row - 1][col + 1];

            //right down (\)
            long long int right_down = (row == m - 1 || col == n - 1) ? 0 : table[row + 1][col + 1];

            table[row][col] = loot[row][col] + max(right, max(right_up, right_down));
        }
    }
    long long int result = table[0][0];
    for (int i = 1; i < m; i++)
        result = max(result, table[i][0]);
    return result;
}

int main()
{

    int m, n;
    cin >> m >> n;
    vector<vector<int>> loot(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> loot[i][j];
    }
    cout << getMaxLoot(loot, m, n);
    return 0;
}