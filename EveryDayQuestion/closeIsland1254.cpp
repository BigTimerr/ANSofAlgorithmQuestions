//
// Created by ruetrash on 2023/6/19.
//


# include <vector>
#include <iostream>
using namespace std;

class Solution {
public:

    void dfs(int x, int y, vector<vector<int>>& grid){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]){
            return;
        }
        grid[x][y] = 1;
        dfs(x-1, y, grid);
        dfs(x+1, y, grid);
        dfs(x, y-1, grid);
        dfs(x, y+1, grid);
    }


    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (m < 3 || n < 3){return 0;}

        for (int i = 0; i < n; ++i) {
            dfs(i,0,grid);
            dfs(i,m-1,grid);
        }
        for (int j = 0; j < m; ++j) {
            dfs(0,j,grid);
            dfs(n-1,j,grid);
        }


        int ans = 0;

        for (int i = 1; i < n-1; ++i) {
            for (int j = 1; j < m-1; ++j) {
                if (grid[i][j] == 0){
                    ++ans;
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> matrix = {
            {0,0,1,0,0},{0,1,0,1,0},{0,1,1,1,0}
    };

    Solution solu = Solution();
    int num = solu.closedIsland(matrix);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout<<matrix[i][j];
        }
    }

}