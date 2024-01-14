#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end()); 
        // set<vector<int>> res ;
        for(int i=0;i<nums.size();i++){
             if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // Skip duplicates
            }
            int temp = nums[i];
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                if(nums[left]+nums[right]+temp==0){
                    ans.push_back({temp,nums[left],nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) { // we can left -1 because we did left++
                        left++; // Skip duplicates
                    }

                    while (left < right && nums[right] == nums[right + 1]) { // we can write right+1 here since already did right--;
                        right--; // Skip duplicates
                    }
                }else if(nums[left]+nums[right]+temp<0){
                    left++;
                }else {
                    right--;
                }
            }
        }
        // for(auto it: res){
        //     ans.push_back(it);
        // }
        return ans;
    }
};

/*
NOTES:

TC: O(n^2)
SC: O(1)

-- skip duplicates reduced time of execution significantly
-- if we don't skip duplicates inside we will have to use set
*/ 


int main(){
    // no solution

    vector<int> input1 = {-1,-1,0};
    Solution solution;
    vector<vector<int>> ans1 = solution.threeSum(input1);
    if(!ans1.size()){
        cout<<"No solution found"<<endl;
    }
    for(auto i: ans1){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

     // 2 solutions

    vector<int> input2 = {-1,-1,0,1,2};
    vector<vector<int>> ans2 = solution.threeSum(input2);
    if(!ans2.size()){
        cout<<"No solution found"<<endl;
    }
    for(auto i: ans2){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
