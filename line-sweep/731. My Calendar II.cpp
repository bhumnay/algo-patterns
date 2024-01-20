#include <iostream>
#include <map>

using namespace std;

// class MyCalendarTwo {
//     map<int,int> line;
// public:

//     MyCalendarTwo() {
//     }

//     bool book(int start, int end) {
//         line[start]++;
//         line[end]--;
//         int count =0;
//         int sum=0;
//         for(auto i: line){
//             sum+=i.second;
//             count=max(sum,count);
//             if(count>=3){
//             line[start]--;
//             line[end]++;
//             return false;
//         }
//         }

//         return true;
//     }
// };

// TC:O(n*nlogn)

class MyCalendarTwo
{
    vector<pair<int, int>> events;
    vector<pair<int, int>> doublebook;

public:
    MyCalendarTwo()
    {
    }

    bool book(int start, int end)
    {
        for (auto p : doublebook)
        { // O(n)
            if (start < p.second && end > p.first)
                return false;
        }

        for (auto p : events)
        { // O(n)
            if (start < p.second && end > p.first)
            {
                doublebook.push_back({max(start, p.first), min(end, p.second)});
            }
        }
        events.push_back({start, end});

        return true;
    }
};

// TC: O(n*n) SC:O(n)

int main()
{
    return 0;
}