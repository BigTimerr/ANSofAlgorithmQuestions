//
// Created by ruetrash on 2023/8/10.
//

# include <vector>
# include <iostream>
# include <algorithm>

using namespace std;

//class Solution {
//public:
//    int minFallingPathSum(vector<vector<int>>& grid) {
//        int n = grid.size();
//        vector<vector<int>> d(n, vector<int>(n, INT_MAX));
//
//        for (int i = 0; i < n; ++i) {
//            d[0][i] = grid[0][i];
//        }
//
//        for (int i = 1; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                for (int k = 0; k < n; ++k) {
//                    if(j == k){
//                        continue;
//                    }
//                    d[i][j] = min(d[i][j], d[i-1][j] + grid[i][k]);
//                }
//            }
//        }
//
//        int res = *min_element(d[n-1].begin(), d[n-1].end());
//
//        return res;
//
//    }
//};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; ++i) {
            sort(grid[i].begin(), grid[i].end());
        }

        if (n==1) return grid[0][0];

        int flag = grid[0][0] <= grid[1][0]? 0:1;
        int flag_bak = (flag + 1) % 2;

        int sum = 0;
        int sum_bak = 0;


        for (int i = 0; i < m; ++i) {
            sum += grid[i][flag];
            flag = (flag + 1) % 2;

            sum_bak += grid[i][flag_bak];
            flag_bak = (flag_bak + 1) % 2;
        }

        return min(sum, sum_bak);

    }
};



//int main(){
//    vector<vector<int>> grid = {{-37,51,-36,34,-22},{82,4,30,14,38},{-68,-52,-92,65,-85},{-49,-3,-77,8,-19},{-60,-71,-21,-62,-73}};
//
//    Solution solution = Solution();
//
//    int res = solution.minFallingPathSum(grid);
//    cout << res << endl;
//}