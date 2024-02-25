// Source: https://leetcode.com/problems/rank-teams-by-votes/

import java.util.Arrays;

class Solution {
    public String rankTeams(String[] votes) {
        int n = votes[0].length();
        int[][] rank = new int[26][27];
        for (int i = 0; i < votes[0].length(); i++) {
            rank[votes[0].charAt(i) - 'A'][26] = votes[0].charAt(i);
        }
        for (String vote : votes) {
            for (int i = 0; i < n; i++) {
                rank[vote.charAt(i) - 'A'][i]--;
            }
        }
        Arrays.sort(rank, (a, b) -> {
            for (int i = 0; i < 27; i++) {
                if (a[i] != b[i]) {
                    return a[i] - b[i];
                }
            }
            return 0;
        });
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 27; j++) {
                System.out.print(rank[i][j] + " ");
            }
            System.out.println();
        }
        String ans = "";
        for (int i = 0; i < n; i++) {
            ans += (char) rank[i][26];
        }
        return ans;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        String[] votes = { "ABC", "ACB", "ABC", "ACB", "ACB" };
        System.out.println(s.rankTeams(votes));
    }
}
