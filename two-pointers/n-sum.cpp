#include <iostream>
using namespace std;

class Solution
{
public:
    void handleNSum(vector<int> nums, int target, int n, int left, int right, vector<int> &path, vector<vector<int>> &ans)
    {
        if (right - left + 1 < n || target < nums[left] * n || target > nums[right] * n)
            return;
        if (n == 2)
        {
            int sum = 0;
            for (int i : path)
            {
                sum += i;
            }
            while (left < right)
            {
                int temp = sum + nums[left] + nums[right];
                if (temp == target)
                {
                    ans.push_back(path);
                    ans.back().push_back(nums[left]);
                    ans.back().push_back(nums[right]);
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else if (target < temp)
                {
                    right--;
                }
                else
                    left++;
            }

            return;
        }
        for (int i = left; i <= right; i++)
        {
            if (i > left && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            handleNSum(nums, target, n - 1, i + 1, right, path, ans);
            path.pop_back();
        }
    }

    void nsum(vector<int> &nums, int target, int n)
    {
        cout << n << " SUM" << endl;
        vector<vector<int>> ans;
        vector<int> path;
        sort(nums.begin(), nums.end());
        handleNSum(nums, target, n, 0, nums.size() - 1, path, ans);
        printResult(ans);
    }

    void printResult(vector<vector<int>> ans)
    {
        for (vector<int> i : ans)
        {
            cout << "{";
            for (int j : i)
            {
                cout << " " << j;
            }
            cout << " }" << endl;
        }
    }
};

int main()
{
    // 2 sum
    vector<int> input1 = {1, 0, 9, -1, 8, -2};
    Solution solution;
    solution.nsum(input1, 8, 2);

    // 3 sum
    vector<int> input2 = {1, 0, 9, -1, 8, -2, 0};
    solution.nsum(input2, 8, 3);

    // 5 sum
    vector<int> input3 = {1, 0, 9, -1, 8, -2, 0, 0, 0};
    solution.nsum(input3, 8, 5);

    // 7 sum
    vector<int> input4 = {1, 0, 9, -1, 8, -2, 0, 0, 0, 0, 0};
    solution.nsum(input4, 8, 7);
}