#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
    bool isValid(string str)
    {
        if (str.size() > 3 || str.size() < 1)
            return false;
        int stringAsInt = stoi(str);
        if (stringAsInt > 255)
            return false;
        if (str[0] == '0' && str.size() > 1)
            return false;
        return true;
    }
    void helper(string strr, int start, vector<string> curr, vector<string> &ans)
    {
        if (curr.size() == 4 && start == strr.size())
        {
            string newStr;
            for (auto it : curr)
            {
                newStr += it + ".";
            }
            newStr.pop_back();
            cout << newStr << "newStr" << endl;
            ans.push_back(newStr);
            return;
        }
        if (curr.size() == 4 && start < strr.size())
            return;
        if (start > strr.size())
            return;
        for (int i = start + 1; i < strr.size(); i++)
        {
            string temp = strr.substr(start, i - start);
            if (isValid(temp))
            {
                cout << temp << endl;
                curr.push_back(temp);
                helper(strr, i, curr, ans);
            }
            curr.pop_back();
        }
    }

public:
    vector<string> validIPAddresses(string strr)
    {
        // Write your code here.
        vector<string> ans;
        vector<string> curr;
        helper(strr, 0, curr, ans); // 1921680
        return {};
    }
};
int main()
{
    Solution s;
    vector<string> ans = s.validIPAddresses("1921680");
    for (auto it : ans)
    {
        cout << it << endl;
    }
}