#include <iostream>>
#include <queue>
using namespace std;

class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        if (nums.size() < 5)
        {
            return 0;
        }

        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i : nums) //O(n)
        {
            minHeap.push(i);
            maxHeap.push(i);
            if (maxHeap.size() > 4)
            {
                maxHeap.pop();
                minHeap.pop();
            }
        }

        vector<int> smallestNum(4,0);
        vector<int> largestNum(4,0);
        for(int i=0;i<4;i++){
            smallestNum[3-i]= maxHeap.top();
            largestNum[i]= minHeap.top();
            maxHeap.pop();
            minHeap.pop();
        }
        int minDiff = INT_MAX;
        for(int i=0;i<4;i++){
            minDiff = min(minDiff,largestNum[i]-smallestNum[i]);
        }

        return minDiff;
    }
};

int main()
{
    return 0;
}