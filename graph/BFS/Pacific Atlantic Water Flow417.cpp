//
// Created by ruetrash on 2023/5/23.
//
# include <vector>
# include <queue>
# include <numeric>
# include <algorithm>
# include <iostream>
# include <unordered_map>

using namespace std;

static const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:

    void dfs(int x, int y , vector<vector<bool>>& ocean, vector<vector<int>>& heights, int n, int m){
        if (ocean[x][y]) return;

        queue<pair<int, int>> q;
        q.emplace(x,y);
        ocean[x][y] = true;
        while(!q.empty()){
            auto currentNode = q.front();
            q.pop();
            for (auto dir : dirs) {
                int currentX = currentNode.first + dir[0], currentY = currentNode.second + dir[1];
                if(currentX>=0 && currentX<n && currentY>=0 && currentY<m
                && heights[currentX][currentY]>=heights[currentNode.first][currentNode.second]
                && !ocean[currentX][currentY]){
                    q.emplace(currentX, currentY);
                    ocean[currentX][currentY] = true;

                }
            }

        }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size(), m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        for (int i = 0; i < n; ++i) {
            dfs(i, 0 , atlantic, heights, n, m);
        }
        for (int j = 1; j < m; ++j) {
            dfs(0, j, atlantic, heights, n, m);
        }

        for (int i = 0; i < n; ++i) {
            dfs(i, m-1 , pacific, heights, n, m);
        }
        for (int j = 0; j < m; ++j) {
            dfs(n-1, j, pacific, heights, n, m);
        }

        vector<vector<int>> result;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (pacific[i][j] && atlantic[i][j]){
                    vector<int> node = {i,j};
                    result.push_back(node);
                }
            }
        }
        return result;
    }
};