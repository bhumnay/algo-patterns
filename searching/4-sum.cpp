#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) // TC:O(n^2) SC:O(n^2)
    {
        set<vector<int>> result;
        unordered_map<int, vector<vector<int>>> twoSumMap;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int currSum = nums[i] + nums[j];
                int reqSum = target - currSum;
                if (twoSumMap.find(reqSum) != twoSumMap.end())
                {
                    for (auto twoSumPair : twoSumMap[reqSum])
                    {
                        vector<int> res = {twoSumPair[0], twoSumPair[1], nums[i], nums[j]};
                        sort(res.begin(), res.end());
                        if (result.find(res) == result.end())
                            result.insert(res);
                    }
                }
            }
            for (int k = 0; k < i; k++)
            {
                int currSum = nums[i] + nums[k];
                twoSumMap[currSum].push_back({nums[i], nums[k]});
            }
        }
        vector<vector<int>> finalRes;
        for (auto res : result)
        {
            finalRes.push_back(res);
        }
        return finalRes;
    }

    vector<vector<int>> fourSum2(vector<int> &nums, int target) // TC:O(n^3) SC:O(n^2)
    {
        set<vector<int>> result; // can't use unordered_set as there is no hash function for vector
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++)
        {
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    int currSum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (currSum == target)
                    {
                        result.insert({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                    }
                    else if (currSum < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }
        vector<vector<int>> finalRes;
        for (auto res : result)
        {
            finalRes.push_back(res);
        }
        return finalRes;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 2, 2, 2};
    int target = 8;
    vector<vector<int>> result = s.fourSum2(nums, target);
    for (auto res : result)
    {
        for (int i : res)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}