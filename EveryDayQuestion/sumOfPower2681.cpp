//
// Created by ruetrash on 2023/8/1.
//
# include <vector>
# include <algorithm>
# include <iostream>
# include <map>

using namespace std;

class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, s = 0;
        int mod = 1e9 + 7;
        for (long long x : nums) {
            ans = (ans + ((x * x) % mod) * (x + s)) % mod;
            s =  (2 * s + x) % mod;
        }

    return ans;

    }
};
