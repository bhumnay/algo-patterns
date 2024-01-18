#include<iostream>
using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> years(101,0);
        for(int i=0;i<logs.size();i++){
            years[logs[i][0]-1950]++; //O(n)
            years[logs[i][1]-1950]--;
        }
        int minYear = 1950;
        int maxPopulation = years[0];
        for(int i=1;i<101;i++){
            years[i]+=years[i-1];
            if(years[i]>maxPopulation){
                maxPopulation = years[i];
                minYear = i+1950;
            }
        }
        return minYear;
    }
};

int main(){
    return 0;
}