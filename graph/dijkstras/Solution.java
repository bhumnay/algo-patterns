package graph.dijkstras;

import java.util.PriorityQueue;

public class Solution {
    int[] dijkstraAlgorithm(int start, int[][][] edges) {
        int[] distance = new int[edges.length];
        int[] visited = new int[edges.length];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for (int i = 0; i < edges.length; i++) {
            distance[i] = Integer.MAX_VALUE;
        }
        pq.add(new int[] { 0, start });
        distance[start] = 0;

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int minVertex = curr[1];
            visited[minVertex] = 1;
            for (int[] edge : edges[minVertex]) {
                int vertex = edge[0];
                int weight = edge[1];
                if (visited[vertex] == 0 && distance[minVertex] + weight < distance[vertex]) {
                    distance[vertex] = distance[minVertex] + weight;
                    pq.add(new int[] { distance[vertex], vertex });
                }
            }
        }
        for (int i = 0; i < edges.length; i++) {
            if (distance[i] == Integer.MAX_VALUE) {
                distance[i] = -1;
            }
        }
        return distance;
    }

    public static void main(String[] args) {
        int[][][] edges = { { { 1, 7 } }, { { 2, 6 }, { 3, 20 }, { 4, 3 } }, { { 3, 14 } }, { { 4, 2 } }, {}, {} };
        int start = 0;
        Solution sol = new Solution();
        int[] result = sol.dijkstraAlgorithm(start, edges);
        for (int i : result) {
            System.out.println(i);
        }
    }
}
