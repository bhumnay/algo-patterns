#include <iostream>
using namespace std;

/*
PROBLEM STATEMENT:
given crystals of weight array [w1, w2, w3 ,....]
with cost given as an array    [c1, c2, c3 ,....]
we can pick crystals worth W such that we can sell them for max profit.


BRUTE:
- We have to check for each PnC of the cryatls so check which combination will give us max profit
- Since there is no trick , we need to iterate and figure out all PnC - recursion/dfs
- here we have choice for each crystal to include or not
TC:O(2^n)    SC: O(n)[call stack, depth of tree]
*/

int bruteDfs(vector<int> &weights, vector<int> &cost, int maxWeigh, int i)
{
    if (i == 0 || maxWeigh == 0)
        return 0;
    if (weights[i] > maxWeigh)
    {
        return bruteDfs(weights, cost, maxWeigh, i - 1);
    }
    return max(bruteDfs(weights, cost, maxWeigh, i - 1), cost[i] + bruteDfs(weights, cost, maxWeigh - weights[i], i - 1));
}

int bruteSolution(vector<int> &weights, vector<int> &cost, int maxWeigh) // O(2^n) [- 2^n steps on each level hence sum of 2^0+2^1...2^n ~ 2^n]
{
    int n = weights.size();
    return bruteDfs(weights, cost, maxWeigh, n - 1);
}

/*
MEMOIZATION:
- since we have 2 states i-th number and weight remaining at each step, we can use 2D array for overlapping problems to cache the solution at each step
TC:O(n*W)  SC:O(n*w)[dp]
*/

int memoizedDfs(vector<int> &weights, vector<int> &cost, int maxWeigh, int i, vector<vector<int>> &dp)
{
    if (i == 0 || maxWeigh == 0)
        return 0;
    if (dp[i][maxWeigh] != -1)
    {
        return dp[i][maxWeigh];
    }
    if (weights[i] > maxWeigh)
    {
        return memoizedDfs(weights, cost, maxWeigh, i - 1, dp);
    }
    dp[i][maxWeigh] = (memoizedDfs(weights, cost, maxWeigh, i - 1, dp), cost[i] + memoizedDfs(weights, cost, maxWeigh - weights[i], i - 1, dp));
    return dp[i][maxWeigh];
}

int memoizedSolution(vector<int> &weights, vector<int> &cost, int maxWeigh)
{
    int n = weights.size();
    int W = maxWeigh;
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    return memoizedDfs(weights, cost, maxWeigh, n - 1, dp);
}

/*
BOTTOM_DOWN:
- this is us going and building from sub problems
TC:O(n*W)  SC:O(n*w)[dp]

*/

int tabulationSolution(vector<int> &weights, vector<int> &cost, int maxWeigh)
{
    int n = weights.size();
    int W = maxWeigh;
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= maxWeigh; j++)
        {
            if (weights[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
                dp[i][j] = max(cost[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
        }
    }
    return dp[n][maxWeigh];
}

/*
1D- dp:
- since we are always concerned about i-1, we can go from n to 0 so that we are maintaining previous iteration result
TC:O(n*W)  SC:O(n*w)[dp]

*/

int oneDSolution(vector<int> &weights, vector<int> &cost, int maxWeigh)
{
    int n = weights.size();
    int W = maxWeigh;
    vector<int> dp(W + 1, 0);
    for (int i = 0; i <=n ; i++)
    {
        for (int j = W; j >= 0; j--)
        {
            if (weights[i - 1] > j)
            {
                continue;
            }
            else
                dp[j] = max(cost[i - 1] + dp[j - weights[i - 1]], dp[j]);
        }
    }
    return dp[maxWeigh];
}

int main()
{
    vector<int> weights = {1, 2, 3, 1, 5, 6};
    vector<int> cost = {1, 2, 3, 4, 5, 6};
    int result = bruteSolution(weights, cost, 10);
    cout << result << endl;

    int result2 = memoizedSolution(weights, cost, 10);
    cout << result2 << endl;

    int result3 = tabulationSolution(weights, cost, 10);
    cout << result3 << endl;

      int result4 = oneDSolution(weights, cost, 10);
    cout << result4 << endl;
    return 0;
}