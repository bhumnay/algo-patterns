#include<iostream>
using namespace std;

class Solution{
    public:
        int numberOfPoints(vector<vector<int>>& nums) {
            vector<int> numLine(101,0);
            int n = nums.size();
            for(int i=0;i<n;i++){
                int start = nums[i][0];
                int end = nums[i][1];
                numLine[start]++;
                if(end<100){
                    numLine[end]--;
                }
            }
            int count = numLine[0];
            for(int i = 1;i<101;i++){
                numLine[i]+=numLine[i-1];
                if(numLine[i]){
                    count++;
                }
            }
            return count;
        }
};

int main(){
    return 0;
}