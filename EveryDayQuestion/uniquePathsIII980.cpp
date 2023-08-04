//
// Created by ruetrash on 2023/8/4.
//

# include <vector>
# include <algorithm>
# include <iostream>

using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int x, int y, int cnt){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y] == -1){
            return 0;
        }
        if(grid[x][y] == 2){
            return cnt == 0;
        }
        grid[x][y] = -1;
        int ans = dfs(grid, x-1, y, cnt-1) + dfs(grid, x+1, y, cnt-1) + dfs(grid, x, y-1, cnt-1)
                + dfs(grid, x, y+1, cnt-1);
        grid[x][y] = 0;
        return ans;
    }



    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int si = 0, sj = 0, cnt = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // 如果当前点是0，那么就让需要通过的点加1
                if (grid[i][j] == 0){
                    cnt ++;
                // 如果当前点是1，那么就让需要通过的点加1，并且将开始的坐标保存下来
                }else if(grid[i][j] == 1){
                    cnt ++;
                    si = i;
                    sj = j;
                }
            }
        }

        return dfs(grid, si, sj, cnt);
    }
};