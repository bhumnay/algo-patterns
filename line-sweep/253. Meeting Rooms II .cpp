#include<iostream>
#include <map>
using namespace std;
class Interval{
    public:
    int start;
    int end;
};
class Solution{
     /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval>& intervals){
        map<int,int> line;
        for(auto i: intervals){ //O(n)
            line[i.start]++; //O(logn)
            line[i.end]--;
        }
        int count = 0;
        int lineSweepSum =0;
        for(auto i: line){ //O(n)
            lineSweepSum+=i.second;
            count = max(count,lineSweepSum);
        }
        return count;
    }
};

//TC:O(n logn)

int main(){
    return 0;
}

/**
 * Approch 1:
 * use map to store number of meeting room at specific interval time hence sorted
 * iterate and use line sweep to find min rooms needed i.e max needed at any point of time
     */