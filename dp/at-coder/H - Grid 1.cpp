#include <iostream>
#include <vector>

using namespace std;
void solution(vector<vector<char>> grid, long long rows, long long cols)
{
    vector<vector<long long>> dp(rows, vector<long long>(cols, 0));
    dp[0][0] = 1;
    for (long long i = 0; i < rows; i++)
    {
        for (long long j = 0; j < cols; j++)
        {
            if (grid[i][j] != '#')
            {
                if (i == 0 && j == 0)
                {
                    continue;
                }
                else if (i == 0)
                {
                    dp[i][j] = dp[i][j - 1];
                }
                else if (j == 0)
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    for (long long i = 1; i < rows; i++)
    {
        for (long long j = 1; j < cols; j++)
        {
            if (grid[i][j] == '#')
            {
                continue;
            }
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
        }
    }
    cout << dp[rows - 1][cols - 1] << endl;
}

int main()
{
    long long rows, cols;
    cin >> rows;
    cin >> cols;
    vector<vector<char>> grid(rows, vector<char>(cols, ' '));
    for (long long i = 0; i < rows; i++)
    {
        for (long long j = 0; j < cols; j++)
        {
            cin >> grid[i][j];
        }
    }

    solution(grid, rows, cols);
}