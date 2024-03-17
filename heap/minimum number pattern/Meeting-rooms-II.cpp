#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int getMinMeetingRooms(vector<vector<int>> &intervals)
{
    vector<vector<int>> sortedIntervals; // O(nlogn)
    sort(
        intervals.begin(), intervals.end(),
        [](const vector<int> &a, const vector<int> &b)
        {
            return a[0] < b[0];
        });
    auto cmp = [](const int &a, const int &b)
    { return a > b; };
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (auto interval : intervals) // O(n)
    {
        if (minHeap.empty())
        {
            minHeap.push(interval[1]); // O(logn)
            continue;
        }
        if (interval[0] >= minHeap.top())
        {
            minHeap.pop();
        }
        minHeap.push(interval[1]);
    }
    return minHeap.size();
}

int main()
{
    vector<vector<int>> intervals = {{15, 30}, {5, 15}, {10, 20}};
    cout << getMinMeetingRooms(intervals) << endl;
    return 0;
}