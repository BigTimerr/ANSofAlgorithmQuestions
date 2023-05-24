//
// Created by ruetrash on 2023/5/14.
//
# include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        int rowSize = grid.size();
        int colSize = grid[0].size();

        grid[i][j] = '0';
        if (i-1 >= 0 && grid[i-1][j] == '1') dfs(grid, i-1 ,j);
        if (i+1 < rowSize && grid[i+1][j] == '1') dfs(grid, i+1 ,j);
        if (j-1 >= 0 && grid[i][j-1] == '1') dfs(grid, i ,j-1);
        if (j+1 < colSize && grid[i][j+1] == '1') dfs(grid, i ,j+1);


    }

    int numIslands(vector<vector<char>>& grid) {
        int rowSize = grid.size();
        if(!rowSize) {return 0;}
        int colSize = grid[0].size();

        int numIsland = 0;
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                if (grid[i][j] == '1'){
                    ++numIsland;
                    dfs(grid,i,j);
                }
            }
        }
        return numIsland;
    }
};

//int main(){
//    vector<vector<char>> matrix = {
//            {'1','1','1','1','0'},
//            {'1','1','0','1','0'},
//            {'1','1','0','0','0'},
//            {'0','0','1','0','1'}
//    };
//
//    Solution solu = Solution();
//    int num = solu.numIslands(matrix);
//    cout<<num;
//}