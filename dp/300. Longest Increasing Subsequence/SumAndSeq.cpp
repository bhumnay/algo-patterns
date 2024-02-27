#include <vector>
#include <iostream>
using namespace std;

class SumAndSeq
{
    vector<int> getMaxLength(vector<int> &nums, int end)
    {
        if (end == 0)
            return {nums[end]};
        int maxLength = 0;
        vector<int> maxArray = {};
        for (int i = 0; i < end; i++)
        {
            if (nums[i] < nums[end])
            {
                vector<int> currArr = getMaxLength(nums, i);
                if (currArr.size() > maxLength)
                {
                    maxLength = currArr.size();
                    maxArray = currArr;
                }
            }
        }

        maxArray.push_back(nums[end]);
        return maxArray;
    }

public:
    vector<vector<int>> maxSumIncreasingSubsequence(vector<int> nums)
    {
        // Write your code here.
        vector<int> maxArr;
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> currArr = getMaxLength(nums, i);
            if (currArr.size() > maxLen)
            {
                maxLen = currArr.size();
                maxArr = currArr;
            }
        }
        int sum = 0;
        for (int i = 0; i < maxArr.size(); i++)
        {
            sum += maxArr[i];
        }
        return {
            {sum},  // Sum of sequence.
            maxArr, // Elements of the sequence.
        };
    }
};

int main()
{
    SumAndSeq s;
    vector<int> nums = {10, 70, 20, 30, 50, 11, 30};
    vector<vector<int>> res = s.maxSumIncreasingSubsequence(nums);
    cout << "Sum: " << res[0][0] << endl;
    cout << "Sequence: ";
    for (int i = 0; i < res[1].size(); i++)
    {
        cout << res[1][i] << " ";
    }
    cout << endl;
    return 0;
}
