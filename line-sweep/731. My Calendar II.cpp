#include<iostream>
#include<map>

using namespace std;

class MyCalendarTwo {
    map<int,int> line;
public:

    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        line[start]++;
        line[end]--;
        int count =0;
        int sum=0;
        for(auto i: line){
            sum+=i.second;
            count=max(sum,count);
            if(count>=3){
            line[start]--;
            line[end]++;
            return false;
        }
        }
        
        return true;
    }
};


//TC:O(n*nlogn)