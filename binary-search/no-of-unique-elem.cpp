#include <iostream>
#include <vector>
using namespace std;
// // TC:O(n*logn) SC:O(log n)
// int leftBound(vector<int> nums, int left, int right)
// {
//     int target = nums[right];
//     int leftIdx = right;
//     while (left <= right)
//     {
//         int mid = (left + right) / 2;
//         if (target == nums[mid])
//         {
//             leftIdx = mid;
//             right = mid - 1;
//         }
//         else
//             left = mid + 1;
//         if (nums[right] != target)
//             break;
//     }
//     return leftIdx - 1;
// }

// int rightBound(vector<int> nums, int left, int right)
// {
//     int target = nums[left];
//     int rightIdx = right;
//     while (left <= right)
//     {
//         int mid = (left + right) / 2;
//         if (target == nums[mid])
//         {
//             rightIdx = mid;
//             left = mid + 1;
//         }
//         else
//             right = mid - 1;
//         if (nums[left] != target)
//             break;
//     }
//     return rightIdx + 1;
// }

// int helper(vector<int> nums, int left, int right)
// {
//     if (left > right)
//         return 0;
//     if (nums[left] == nums[right])
//         return 1;
//     int mid = (left + right) / 2;

//     return 1 + helper(nums, left, leftBound(nums, left, mid)) + helper(nums, rightBound(nums, mid, right), right);
// }

int noOFUnique(vector<int> nums) // TC:O(log(n)) -best case worst case O(n)
{
    // return helper(nums, 0, nums.size() - 1);
    int start = 0;
    int end = nums.size() - 1;
    int count = 0;
    int prevElem = -1;
    int counter = 0;
    while (start <= end)
    {
        counter++;
        int mid = (start + end) / 2;
        if (prevElem == -1)
        {
            prevElem = nums[start];
            count++;
        }
        else if (prevElem != nums[start])
        {
            count++;
            prevElem = nums[start];
        }
        if (nums[start] == nums[mid])
            start = mid + 1;
        else
            start++;
    }
    cout << counter << endl;
    return count;
}

int main()
{
    vector<int> input = {1, 1, 1, 1, 4, 6, 6};
    cout << noOFUnique(input);
}