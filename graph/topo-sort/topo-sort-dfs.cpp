#include <vector>
#include <stack>
#include <iostream>
using namespace std;
// DFS based approch
bool dfs(stack<int> &stackk, unordered_map<int, vector<int>> adjList, int curr, unordered_map<int, int> &visited)
{
    if (visited[curr] == 1)
        return true;
    if (visited[curr] == 2)
        return false;
    visited[curr] = 2;
    for (int i : adjList[curr])
    {
        if (dfs(stackk, adjList, i, visited) == false)
            return false;
    }
    visited[curr] = 1;
    stackk.push(curr);
    return true;
}

vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps)
{
    vector<int> result;
    unordered_map<int, int> visited;
    for (int i = 0; i < jobs.size(); i++)
    { // O(V)
        visited[jobs[i]] = 0;
    }
    unordered_map<int, vector<int>> adjList;

    for (int i = 0; i < deps.size(); i++)
    { // O(E)
        adjList[deps[i][0]].push_back(deps[i][1]);
    }
    stack<int> stackk;
    for (auto i : jobs)
    {
        if (visited[i] == 0)
        {
            if (dfs(stackk, adjList, i, visited) == false)
                return {}; // O(V+E)
        }
    }
    while (!stackk.empty())
    { // O(V)
        result.push_back(stackk.top());
        stackk.pop();
    }
    return result;
}

// TC:O(V+E) SC:O(V+E)

int main()
{
    vector<int> jobs = {1, 2, 3, 4};
    vector<vector<int>> deps = {{1, 2}, {1, 3}, {3, 2}, {4, 2}, {4, 3}};
    vector<int> result = topologicalSort(jobs, deps);
    for (int i : result)
    {
        cout << i << " ";
    }
    return 0;
}
