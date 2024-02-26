package LongestCommonSubSequence;

import java.util.ArrayList;
import java.util.List;

public class Solution {

    public static List<Character> longestCommonSubsequence(
            String str1, String str2) {
        // Write your code here.
        List<Character> result = new ArrayList<>();
        int len1 = str1.length();
        int len2 = str2.length();
        int[][] dp = new int[len1 + 1][len2 + 1];

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else
                    dp[i][j] = Math.max(Math.max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
                System.out.print(dp[i][j]);
            }
            System.out.println();
        }
        int idx1 = len1;
        int idx2 = len2;
        while (idx1 > 0 && idx2 > 0) {
            if (str1.charAt(idx1 - 1) == str2.charAt(idx2 - 1)) {
                result.add(0, str1.charAt(idx1 - 1));
                idx1--;
                idx2--;
            } else {
                if (dp[idx1 - 1][idx2] > dp[idx1][idx2 - 1]) {
                    idx1--;
                } else {
                    idx2--;
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        String str1 = "ZXVVYZW";
        String str2 = "XKYKZPW";
        System.out.println(longestCommonSubsequence(str1, str2));
    }
}
