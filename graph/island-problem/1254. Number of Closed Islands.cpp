#include <iostream>

using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int row, int col, int x, int y)
    {
        if (x < 0 || y < 0 || x >= row || y >= col || grid[x][y] == 1 )
            return ;
      
        grid[x][y] = 1;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int tempX = x + dx[i];
            int tempY = y + dy[i];
             dfs(grid, row, col, tempX, tempY);
        }
    }
    int numOfClosedIsland(vector<vector<int>> &grid)
    {
        int row = grid.size();
        if (row == 0)
            return 0;
        int col = grid[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i*j==0||i==row-1||j==col-1){
                    dfs(grid,row,col,i,j); //flood fill : important
                }
            }
        }

        int count = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 0)
                {
                    dfs(grid, row, col, i, j);
                   count++;
                }
            }
        }
        return count;
    }
};

int main()
{

    // 1. Contains closed island

    vector<vector<int>> grid1 = {
        {0, 1, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 1, 1, 1},
    };
    Solution solution;
    int numOfIsland1 = solution.numOfClosedIsland(grid1);
    cout << "No of island 1 " << numOfIsland1 << endl;

    // 2. Contains open and closed island

    vector<vector<int>> grid2 = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 1, 1, 1},
    };
    int numOfIsland2 = solution.numOfClosedIsland(grid2);
    cout << "No of island 2 " << numOfIsland2 << endl;

    // 3. Contains open  island

    vector<vector<int>> grid3 = {
    {  0, 0, 1, 1, 0, 1, 0, 0, 1, 0 },
  { 1, 1, 0, 1, 1, 0, 1, 1, 1, 0 },
  { 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
  { 0, 1, 1, 0, 0, 0, 0, 1, 0, 1 },
  { 0, 0, 0, 0, 0, 0, 1, 1, 1, 0 },
  { 0, 1, 0, 1, 0, 1, 0, 1, 1, 1 },
  { 1, 0, 1, 0, 1, 1, 0, 0, 0, 1 },
  { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
  { 1, 1, 1, 0, 0, 1, 0, 1, 0, 1 },
  { 1, 1, 1, 0, 1, 1, 0, 1, 1, 0 } 
    };
    int numOfIsland3 = solution.numOfClosedIsland(grid3);
    cout << "No of island 3 " << numOfIsland3 << endl;
    return 0;
}