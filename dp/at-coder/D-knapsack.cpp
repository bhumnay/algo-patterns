#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int helper(int i, vector<int> w, vector<int> v, int maxWeight) // TC:O(2^n) SC:O(n)
{
    if (i == 0 || maxWeight == 0)
        return 0;
    if (maxWeight < w[i - 1])
        return helper(i - 1, w, v, maxWeight);
    return max(helper(i - 1, w, v, maxWeight), v[i - 1] + helper(i - 1, w, v, maxWeight - w[i - 1]));
}

int helper2(int n, vector<long long int> w, vector<long long int> v, int maxWeight)
{
    vector<vector<long long int>> dp(n + 1, vector<long long int>(maxWeight + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxWeight; j++)
        {
            if (j >= w[i - 1])
            {
                dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][maxWeight];
}
int main()
{
    int n;
    int maxWeight;
    cin >> n >> maxWeight;
    vector<long long int> w(n);
    vector<long long int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    int result = helper2(n, w, v, maxWeight);
    cout << result << endl;
}