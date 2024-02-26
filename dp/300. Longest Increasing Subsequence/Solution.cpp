#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int getMaxLength(vector<int> &nums, int end)
    {
        if (end == 0)
            return 1;
        int maxLength = 0;
        for (int i = 0; i < end; i++)
        {
            if (nums[i] < nums[end])
            {
                int currlen = getMaxLength(nums, i);
                maxLength = max(maxLength, currlen);
            }
        }
        return maxLength + 1;
    }
    int lengthOfLISRecursion(vector<int> &nums) // TC:O(2^n) SC:O(n)
    {
        int maxlength = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            maxlength = max(maxlength, getMaxLength(nums, i));
        }
        return maxlength;
    }

    int lengthOfLISDP(vector<int> &nums) // TC:O(n^2) SC:O(n)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxLength = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            maxLength = max(maxLength, dp[i]);
        }
        return maxLength;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << s.lengthOfLISRecursion(nums) << endl;
    cout << s.lengthOfLISDP(nums);
}
