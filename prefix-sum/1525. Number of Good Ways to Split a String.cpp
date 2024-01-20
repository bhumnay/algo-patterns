#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int numSplits(string s)
    {
        unordered_set<char> charSet; // use unordered becoz O(1) insert
        vector<int> leftCount;
        vector<int> rightCount(s.size()); // predefine size so that you can insert from end
        // Prefix sum from left.
        for (char c : s)
        {
            charSet.insert(c);
            leftCount.push_back(charSet.size());
        }
        // Prefix sum from right.
        unordered_set<char> charSet2;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            charSet2.insert(s[i]);
            rightCount[i] = (charSet2.size());
        }
        int count = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (leftCount[i] == rightCount[i + 1])
                count++;
        }
        return count;
    }
};

//TC: O(n)

int main(){
    return 0;
}
