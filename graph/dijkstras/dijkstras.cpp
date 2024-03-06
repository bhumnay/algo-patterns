#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) // TC:O((V+E)*log(V)) SC:O(V)
{
    vector<int> distance(edges.size(), INT_MAX); // SC:O(V)
    distance[start] = 0;
    vector<bool> visited(edges.size(), 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // SC:O(V)
    pq.push({0, start});
    while (!pq.empty()) // O(V)
    {
        int minVertex = pq.top().second;
        pq.pop(); // O(log(V))
        visited[minVertex] = true;
        for (auto neighbour : edges[minVertex]) // O(E)
        {
            int vertex = neighbour[0];
            int weight = neighbour[1];
            if (!visited[vertex] && distance[minVertex] + weight < distance[vertex])
            {
                distance[vertex] = distance[minVertex] + weight;
                pq.push({distance[vertex], vertex});
            }
        }
    }
    for (int i = 0; i < edges.size(); i++)
    {
        if (distance[i] == INT_MAX)
            distance[i] = -1;
    }
    return distance;
}

int main()
{
    vector<vector<vector<int>>> edges = {
        {{1, 7}},
        {{2, 6}, {3, 20}, {4, 3}},
        {{3, 14}},
        {{4, 2}},
        {},
    };
    vector<int> result = dijkstrasAlgorithm(0, edges);
    for (int i : result)
    {
        cout << i << " ";
    }
    return 0;
}
