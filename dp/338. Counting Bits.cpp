#include <iostream>
using namespace std;
//NOTE: not much diff seen in memory or time among the  approaches
class Solution
{
public:
    /*
    BRUTE:
    - count bit of each i and stite the same
    TC: O(n!) SC:O(1)
    */
    int countBitBrute(int n)
    {
        int count = 0;
        while (n)
        {
            int res = n % 2;
            n = n >> 1;
            count += res;
        }
        return count;
    }
    vector<int> countBitsBrute(int n)
    {
        vector<int> ans;

        for (int i = 0; i <= n; i++)
        {
            ans.push_back(countBitBrute(i));
        }
        return ans;
    }

    /*
    Reuse the existing result - use caching hence dp
    - WARN::: TLE - check for &
    - TC=O(n) SC: O(n)
    */
    int countBit2(int n, vector<int> &ans)
    {
        if (ans[n] != -1)
            return ans[n];
        int res = n & 1;
        ans[n] = res + countBit2(n >> 1, ans);
        return ans[n];
    }

    vector<int> countBits2(int n)
    {
        vector<int> ans(n + 1, -1);
        ans[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            ans[i] = countBit2(i, ans);
        }
        return ans;
    }

    /*
    -1D dp
     TC:O(n)  SC:O(1)
    */

    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1, -1);
        ans[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            int res = i & 1;
            ans[i] = ans[i >> 1] + res;
            cout << ans[i] << " ";
        }
        return ans;
    }
};

int main()
{
    Solution solution;

    solution.countBits(85723);
}