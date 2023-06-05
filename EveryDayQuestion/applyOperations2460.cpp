//
// Created by ruetrash on 2023/6/5.
//

#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int count = 0;

        for (int i = 0; i < n-1; ++i) {
            if (nums[i] == nums[i+1] && nums[i]!=0){
                nums[i] += nums[i+1];
                nums[i+1] = 0;
            }

        }
        for (int i = 0; i < n; ++i) {
            if (nums[i]!=0){
            ans[count++] = nums[i];
            }
        }
        return ans;
    }
};