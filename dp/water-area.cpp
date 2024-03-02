#include <vector>
#include <iostream>
#include <climits>

using namespace std;

int waterArea(vector<int> heights)
{
    int leftIdx = 0;
    int rightIdx = heights.size() - 1;
    int total = 0;
    int leftMax = heights[leftIdx];
    int rightMax = heights[rightIdx];

    while (leftIdx < rightIdx)
    {
        if (leftMax < rightMax)
        {
            total += leftMax - heights[leftIdx];
            leftIdx++;
            leftMax = max(leftMax, heights[leftIdx]);
        }
        else
        {
            total += rightMax - heights[rightIdx];
            rightIdx--;
            rightMax = max(rightMax, heights[rightIdx]);
        }
    }
    return total;
}

int main()
{
    vector<int> heights = {0,
                           8,
                           0,
                           0,
                           5,
                           0,
                           0};
    cout << waterArea(heights) << endl;
}