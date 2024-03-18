#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class MedianFinder
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder()
    {
    }
    void addNum(int num) // TC:O(logn)
    {
        if (maxHeap.empty() || maxHeap.top() > num)
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }
        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() // TC:O(1)
    {
        if (minHeap.size() == maxHeap.size())
        {
            return double(minHeap.top() + maxHeap.top()) / 2.0;
        }
        return maxHeap.top();
    }
};

int main()
{
    MedianFinder *obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    cout << obj->findMedian() << endl;
    obj->addNum(-1);
    cout << obj->findMedian() << endl;
    return 0;
}