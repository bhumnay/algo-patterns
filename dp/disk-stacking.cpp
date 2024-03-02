#include <vector>
#include <iostream>
using namespace std;

// TC:O(n^2) SC:O(n)
bool areValid(vector<int> &otherDisk, vector<int> &currDisk)
{
    return otherDisk[0] < currDisk[0] && otherDisk[1] < currDisk[1] && otherDisk[2] < currDisk[2];
}

vector<vector<int>> buildSequence(vector<vector<int>> &disks, vector<int> &sequences, int maxHeightIdx)
{
    vector<vector<int>> ans;
    while (maxHeightIdx != -1)
    {
        ans.insert(ans.begin(), disks[maxHeightIdx]);
        maxHeightIdx = sequences[maxHeightIdx];
    }
    return ans;
}
vector<vector<int>> diskStacking(vector<vector<int>> disks)
{
    sort(disks.begin(), disks.end(), [](vector<int> &a, vector<int> &b)
         { return a[2] < b[2]; });
    vector<int> heights; // dp array
    for (auto disk : disks)
    {
        heights.push_back(disk[2]);
    }
    int maxheightIdx = 0;
    vector<int> sequences(disks.size(), -1);
    for (int i = 0; i < disks.size(); i++)
    {
        vector<int> currDisk = disks[i];
        for (int j = 0; j < i; j++)
        {
            vector<int> otherDisk = disks[j];
            if (!areValid(otherDisk, currDisk))
                continue;
            if (heights[i] <= heights[j] + currDisk[2])
            {
                heights[i] = heights[j] + currDisk[2];
                sequences[i] = j;
            }
        }
        if (heights[i] >= heights[maxheightIdx])
        {
            maxheightIdx = i;
        }
    }

    return buildSequence(disks, sequences, maxheightIdx);
}

int main()
{
    vector<vector<int>> disks = {{2, 1, 2}, {3, 2, 3}, {2, 2, 8}, {2, 3, 4}, {1, 3, 1}, {4, 4, 5}};
    vector<vector<int>> ans = diskStacking(disks);
    for (auto disk : ans)
    {
        for (int i : disk)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}