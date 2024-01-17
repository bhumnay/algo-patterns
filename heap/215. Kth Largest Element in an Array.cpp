#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(int i=0;i<nums.size();i++){
            if(minHeap.size()==k){
                if(minHeap.top()<nums[i]){
                    minHeap.pop();
                }
            }
            if(minHeap.size()<k){
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
    }
};

int main(){
    return 0;
}