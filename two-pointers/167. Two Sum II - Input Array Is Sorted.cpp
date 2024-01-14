#include <iostream>
using namespace std;
// Question - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
class Solution
{
public:
    static vector<int> twoSum(vector<int> &nums, int target)
    {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        while (left < right)
        {
            int temp = nums[left] + nums[right];
            if (temp == target)
            {
                return vector<int>(left + 1, right + 1);
            }
            else if (temp < target)
            {
                left++;
            }
            else
                right--;
        }
        return vector<int>();
    }
};

int main()
{
    Solution mySolution;
    // 1. single existing solution
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> ans1 = mySolution.twoSum(nums1, target1);
    cout << "Test case 1: ";
    if (ans1.empty())
    {
        cout << "No solution found." << endl;
    }
    else
    {
        cout << "Indices of the two numbers: " << ans1[0] << ", " << ans1[1] << endl;
    }

    // 2. no existing solution
    vector<int> nums2 = {2, 11, 11, 15};
    int target2 = 100;
    vector<int> ans2 = mySolution.twoSum(nums2, target2);
    cout << "Test case 2: ";
    if (ans2.empty())
    {
        cout << "No solution found." << endl;
    }
    else
    {
        cout << "Indices of the two numbers: " << ans2[0] << ", " << ans2[1] << endl;
    }
    return 0;
}