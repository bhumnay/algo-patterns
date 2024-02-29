#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses, vector<int>(0));
        for (int i = 0; i < prerequisites.size(); i++)
        {
            indegree[prerequisites[i][0]]++;
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> queue;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                queue.push(i);
        }
        int count = 0;
        while (!queue.empty())
        {
            count++;
            int currVertex = queue.front();
            queue.pop();
            for (int neighbour : adjList[currVertex])
            {
                if (indegree[neighbour] == 0)
                    return false;
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                {
                    queue.push(neighbour);
                }
            }
        }
        return count == numCourses;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    int numCourses = 2;
    bool result = s.canFinish(numCourses, prerequisites);
    cout << result << endl;

    vector<vector<int>> prerequisites1 = {{1, 0}};
    int numCourses1 = 2;
    bool result1 = s.canFinish(numCourses1, prerequisites1);
    cout << result1;
    return 0;
}