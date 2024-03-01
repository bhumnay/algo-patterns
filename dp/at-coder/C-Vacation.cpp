#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{

    int n;
    cin >> n;

    vector<vector<int>> dp(n, vector<int>(3, 0)); // SC:O(n)
    int v[n][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; i++) // TC:O(n)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 0)
            {
                dp[i][j] = v[i][j];
            }
            else
            {
                dp[i][j] = v[i][j] + max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
            }
        }
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}
