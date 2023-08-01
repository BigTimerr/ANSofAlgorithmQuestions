//
// Created by ruetrash on 2023/7/27.
//
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; ++i) {
            sort(grid[i].begin(), grid[i].end());
        }

        int sum = 0;
        for (int j = 0; j < m; ++j) {
            int max_value = INT_MIN;
            for (int i=0; i<n; i++ ) {
                max_value = max(max_value, grid[i][j]);
            }
            sum += max_value;
        }

        return sum;

    }
};