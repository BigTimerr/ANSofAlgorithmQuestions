//
// Created by ruetrash on 2023/7/5.
//
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();

        for (int i = 0; i < n; ++i) {
            sort(nums[i].begin(), nums[i].end());
        }

        int sum = 0;

        for (int i = 0; i < m; ++i) {
            int max_value = 0;
            for (int j = 0; j < n; ++j) {
                max_value = max(max_value, nums[j][i]);
            }
            sum = sum + max_value;
        }

        return sum;

    }
};