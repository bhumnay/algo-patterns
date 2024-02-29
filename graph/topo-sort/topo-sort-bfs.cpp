#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
// BFS based approach or Kahn's algo
vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps)
{
    unordered_map<int, int> indegree;
    unordered_map<int, vector<int>> adjList;
    for (int i = 0; i < jobs.size(); i++)
    { // O(V)
        indegree[jobs[i]] = 0;
        adjList[jobs[i]] = {};
    }
    for (int i = 0; i < deps.size(); i++)
    { // O(E)
        adjList[deps[i][0]].push_back(deps[i][1]);
        indegree[deps[i][1]]++;
    }

    queue<int> zeroDegree;
    for (int i : jobs)
    { // O(V)
        if (indegree[i] == 0)
        {
            zeroDegree.push(i);
        }
    }
    vector<int> result;
    while (!zeroDegree.empty()) // O(V+E)
    {
        int temp = zeroDegree.front();
        result.push_back(temp);
        zeroDegree.pop();
        for (int i : adjList[temp])
        {
            if (indegree[i] > 0)
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    zeroDegree.push(i);
                }
            }
        }
    }
    if (result.size() == jobs.size())
    {
        return result;
    }
    return {};
}
// Time Complexity: O(V+E) SC: O(V+E)

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
