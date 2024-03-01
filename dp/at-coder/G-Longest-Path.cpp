#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int i, vector<vector<int>> &adjList, vector<int> &maxPath, int path) // TC:O(n)
{
    maxPath[i] = max(maxPath[i], path);
    for (int neighbour : adjList[i])
    {
        dfs(neighbour, adjList, maxPath, path + 1);
    }
}

void bruteForce(int n, vector<vector<int>> &adjList, int path) // TC:O(n)
{
    vector<int> maxPath(n, 0);
    for (int i = 0; i < n; i++) // TC:O(n)
    {
        for (int neighbour : adjList[i]) // TC:O(m)
        {

            dfs(neighbour, adjList, maxPath, 1); // TC:O(n)
        }
    }
    int maxPathLength = 0;
    for (int i = 0; i < n; i++)
    {
        maxPathLength = max(maxPathLength, maxPath[i]);
    }
    cout << maxPathLength;
}

int dfsOptimised(int i, vector<vector<int>> &adjList, vector<int> &dp) // TC:O(n)
{
    if (dp[i] != -1)
        return dp[i];
    int maxPath = 0;
    for (int neighbour : adjList[i]) // TC:O(m)
    {
        maxPath = max(maxPath, dfsOptimised(neighbour, adjList, dp) + 1);
    }
    return dp[i] = maxPath;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n, vector<int>(0));
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adjList[x - 1].push_back(y - 1);
    }

    vector<int> dp(n, -1); // SC:O(n)
    int maxPathLength = 0;
    for (int i = 0; i < n; i++) // TC:O(n)
    {
        maxPathLength = max(maxPathLength, dfsOptimised(i, adjList, dp));
    }

    cout << maxPathLength;
}