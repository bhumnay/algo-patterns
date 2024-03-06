#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int minimumEffortPath(vector<vector<int>> &matrix) // TC:O(m*n*log(m*n)) SC:O(m*n)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> distances(rows, vector<int>(cols, INT_MAX));
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    distances[0][0] = 0;
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int count = 0;
    // djikstra
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq; // SC:O(m*n)
    pq.push({0, {0, 0}});
    int maxEffort = 0;
    while (!pq.empty()) // TC:O(m*n*log(m*n))
    {
        auto curr = pq.top(); // TC:O(log(m*n))
        pq.pop();
        int currDist = curr.first;
        vector<int> currPos = curr.second;
        int i = currPos[0];
        int j = currPos[1];
        maxEffort = max(maxEffort, distances[i][j]);
        if (i == rows - 1 && j == cols - 1)
            return maxEffort;
        if (visited[i][j])
            continue;
        visited[i][j] = 1;
        for (auto dir : dirs) // TC:O(4)
        {
            int x = i + dir[0];
            int y = j + dir[1];
            if (x >= 0 && x < rows && y >= 0 && y < cols && !visited[x][y])
            {
                int effort = abs(matrix[i][j] - matrix[x][y]);
                int newDist = min(distances[x][y], effort);
                if (newDist < distances[x][y])
                {
                    distances[x][y] = newDist;
                    pq.push({newDist, {x, y}});
                }
            }
        }
    }
    return maxEffort;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    cout << minimumEffortPath(matrix) << endl;
    return 0;
}