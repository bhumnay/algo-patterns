#include <iostream>
#include <vector>
using namespace std;

int frogJump(int n, vector<int> &heights)
{
    // vector<int> dp(n,0); //1 D dp array
    // dp[0]=0;
    // dp[1]=abs(heights[1]-heights[0]);
    // for(int i=2;i<n;i++){
    //     dp[i]=min(abs(heights[i]-heights[i-1])+dp[i-1],abs(heights[i]-heights[i-2])+dp[i-2]);
    // }
    // return dp[n-1];
    int first = 0;
    int second = abs(heights[1] - heights[0]); // constant space
    for (int i = 2; i < n; i++)
    {
        int third = min(abs(heights[i] - heights[i - 1]) + second, abs(heights[i] - heights[i - 2]) + first);
        first = second;
        second = third;
    }
    return second;
    // if(n==1)return 0; // recursion
    // if(n==2)return abs(heights[1]-heights[0]);
    // if(n==3)return min(abs(heights[2]-heights[0]),abs(heights[2]-heights[1])+abs(heights[1]-heights[0]));
    // return min(abs(heights[n-1]-heights[n-2])+frogJump(n-1,heights),abs(heights[n-1]-heights[n-3])+frogJump(n-2,heights));
    // Write your code here.
}

int main()
{
    vector<int> heights = {30, 10, 60, 10, 60, 50};
    cout << frogJump(heights.size(), heights) << endl;
    return 0;
}