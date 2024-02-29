#include <iostream>
#include <vector>
using namespace std;

// TC:O(V+E) SC:O(V)
class Solution
{
public:
    bool dfs(vector<vector<int>> &graph, vector<int> &visited, int currVertex, int currColor)
    {
        visited[currVertex] = currColor;
        for (int i : graph[currVertex])
        {
            if (visited[i] == currColor)
                return false;
            if (visited[i] == 0)
            {
                if (!dfs(graph, visited, i, -currColor))
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int currColor = 1;
        vector<int> visited(graph.size(), 0);
        for (int i = 0; i < graph.size(); i++)
        {
            if (visited[i] == 0)
            {
                if (!dfs(graph, visited, i, currColor))
                    return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    cout << s.isBipartite(graph) << endl;
    vector<vector<int>> graph1 = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    cout << s.isBipartite(graph1) << endl;
    return 0;
}