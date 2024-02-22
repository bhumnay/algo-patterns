#include <iostream>
using namespace std;

class Solution
{
public:
    int solutionUsingRecursion(string str1, string str2)
    {
        if (str1.length() == 0) // If string 1 is empty, then we need to insert all characters of string 2
        {
            return str2.length();
        }
        if (str2.length() == 0) // If string 2 is empty, then we need to delete all characters of string 1
        {
            return str1.length();
        }
        if (str1[str1.length() - 1] == str2[str2.length() - 1])
        {
            return solutionUsingRecursion(str1.substr(0, str1.length() - 1), str2.substr(0, str2.length() - 1));
        }
        return 1 + min(solutionUsingRecursion(str1.substr(0, str1.length() - 1), str2.substr(0, str2.length() - 1)), // Replaceed last index of string 1 with last index of string 2
                       min(solutionUsingRecursion(str1, str2.substr(0, str2.length() - 1)),                          // inserted in string 1 same as last index of string 2
                           solutionUsingRecursion(str1.substr(0, str1.length() - 1), str2)));                        // deleted the last index of string 1
    }

    int solutionUsing2Ddp(string str1, string str2)
    {
        int m = str1.length();
        int n = str2.length();
        int dp[m + 1][n + 1];
        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = i;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = i;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
                }
            }
        }
        return dp[m][n];
    }

    int solutionUsing1Ddp(string str1, string str2)
    {
        int len1 = str1.length();
        int len2 = str2.length();
        string small = str1;
        string big = str2;
        if (len2 < len1)
        {
            small = str2;
            big = str1;
        }
        int prev[small.length() + 1];
        int curr[small.length() + 1];

        for (int i = 0; i <= small.length(); i++)
        {
            prev[i] = i;
        }

        for (int i = 1; i <= big.size(); i++)
        {
            curr[0] = i;
            for (int j = 1; j <= small.size(); j++)
            {
                if (big[i - 1] == small[j - 1])
                {
                    curr[j] = prev[j - 1];
                }
                else
                {
                    curr[j] = 1 + min(prev[j - 1], min(curr[j - 1], prev[j]));
                }
            }
            for (int j = 0; j <= small.size(); j++)
            {
                prev[j] = curr[j];
            }
        }
        return curr[small.size()];
    }
};

int main()
{
    string str1 = "sunday";
    string str2 = "saturday";
    Solution obj;
    cout << obj.solutionUsingRecursion(str1, str2) << endl;
    cout << obj.solutionUsing2Ddp(str1, str2) << endl;
    cout << obj.solutionUsing1Ddp(str1, str2) << endl;
}

/*
Question - change string 1 to string 2 in minimum number of operations
Operations -
    1. Insert
    2. Delete
    3. Replace

Its always possible to do this by deleted all characters of string 1 and then inserting all characters of string 2.
But this is not the minimum number of operations.


Naive approach -
    1. If last characters of both strings are same, then ignore last characters and continue;
    2. If last characters are not same, then consider all 3 operations
    Since try all 3 operations and get min of all 3, we can use recursion.


    Time complexity - O(3^n)
    Space complexity - O(n) - depth of recursion stack


Optimized approach - Using DP
    1. Create a 2D array of size m+1 and n+1 where m is length of string 1 and n is length of string 2
    2. dp[i][j] will store the minimum number of operations to convert string 1 of length i to string 2 of length j
    3. Fill the first row and first column with 0 to m and 0 to n respectively
    4. Now fill the dp array
        - If last characters of both strings are same, then dp[i][j] = dp[i-1][j-1]
        - If last characters are not same, then dp[i][j] = 1 + min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j])
    5. Return dp[m][n]

    Time complexity - O(m*n)
    Space complexity - O(m*n)


Optimized approach - Using 1D array
    1. Maintain prev & curr array of length of smaller string
    2. Fill the prev array with 0 to ith index with value i

    3. Now fill the array
        - curr[0] = i
        - If last characters of both strings are same, then curr[j] = prev[j-1]
        - If last characters are not same, then curr[j] = 1 + min(prev[j-1], curr[j-1], prev[j])
    4. Return curr[m]

    Time complexity - O(m*n)
    Space complexity - O(min(m,n))
*/