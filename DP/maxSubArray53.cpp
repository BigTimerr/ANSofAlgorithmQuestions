//
// Created by ruetrash on 2023/7/24.
//

# include <vector>
# include <algorithm>
# include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int max_value = INT_MIN;
        max_value = max(dp[0], max_value);
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i-1] < 0 ? nums[i] : dp[i-1] + nums[i];
            max_value = max(max_value, dp[i]);
        }

        return max_value;
    }
};