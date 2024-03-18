#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums) // TC:O(n) SC:O(1)
    {
        vector<string> ans;
        int idx = 0;
        while (idx < nums.size())
        {
            int temp = idx;
            while (temp < nums.size() - 1 && nums[temp + 1] == nums[temp] + 1)
            {
                temp++;
            }
            if (temp == idx)
            {
                ans.push_back(to_string(nums[idx]));
            }
            else
            {
                ans.push_back(to_string(nums[idx]) + "->" + to_string(nums[temp]));
            }
            idx = temp + 1;
        }
        return ans;
    }

    vector<string> summaryRangesWithK(vector<int> &nums, int k)
    {
        vector<string> ans;
        int idx = 0;
        while (idx < nums.size())
        {
            int temp = idx;
            while (temp < nums.size() - 1 && nums[temp + 1] - nums[temp] == k)
            {
                temp++;
            }
            if (temp == idx)
            {
                ans.push_back(to_string(nums[idx]));
            }
            else
            {
                ans.push_back(to_string(nums[idx]) + "->" + to_string(nums[temp]));
            }
            idx = temp + 1;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    vector<string> ans = s.summaryRanges(nums);
    for (string i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> nums1 = {0, 2, 4, 8, 10, 12, 14, 16, 18, 20};
    vector<string> ans1 = s.summaryRangesWithK(nums1, 2);
    for (string i : ans1)
    {
        cout << i << " ";
    }
    cout << endl;
}