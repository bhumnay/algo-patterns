import java.util.PriorityQueue;

public class Solution {

    public int connectSticks(int[] sticks) {
        int result = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int stick : sticks) { // O(nlog n)
            pq.add(stick);
        }
        while (pq.size() > 1) {
            int sum = pq.poll() + pq.poll();
            result += sum;
            pq.add(sum);
        }
        return result;
    }

    public static void main(String[] args) {
        int[] sticks = { 2, 4, 3 };
        Solution solution = new Solution();
        System.out.println(solution.connectSticks(sticks));
    }
}
