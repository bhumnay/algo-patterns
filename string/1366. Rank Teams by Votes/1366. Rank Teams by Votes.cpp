#include <iostream>
using namespace std;

class Solution
{
public:
    string rankTeams(vector<string> &votes)
    {
        vector<vector<int>> count(26, vector<int>(27)); // O(26*27)
        for (char &c : votes[0])                        // O(n)
            count[c - 'A'][26] = c;
        for (string &vote : votes)                    // O(n*m)
            for (int i = 0; i < votes[0].size(); ++i) // O(m)
                --count[vote[i] - 'A'][i];
        sort(count.begin(), count.end()); // O(26*27log26)
        string res;
        for (int i = 0; i < votes[0].size(); ++i) // O(m)
            res += count[i][26];
        return res;
    }
};

// TC: O(26*27 + n*m + 26*27log26 + m) ~ O(n*m)

int main()
{
    Solution s;
    vector<string> votes = {"ABC", "ACB", "ABC", "ACB", "ACB"};
    cout << s.rankTeams(votes);
    return 0;
}