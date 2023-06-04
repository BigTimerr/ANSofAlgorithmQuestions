//
// Created by ruetrash on 2023/6/4.
//
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> res;
        for (int i = 0, j = nums.size() - 1; i < nums.size(); ++i, --j) {
            res.insert(nums[i] + nums[j]);
        }
        return res.size();
    }
};