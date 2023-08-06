//
// Created by ruetrash on 2023/7/31.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX, sum = 0;
        int l = 0, r = 0;
        while(r < n){
            sum += nums[r];
            while(sum >= target){
                ans = min(ans, r-l+1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return ans==INT_MAX? 0:ans;
    }
};

//class Solution {
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//        // sort(nums.begin(), nums.end());
//        int n = nums.size();
//        int res = INT_MAX;
//
//
//        for (int i = 0; i < n; ++i) {
//            int sum = 0;
//            for (int j = i; j < n; ++j) {
//                sum += nums[j];
//                if(sum >= target){
//                    res = min(res, j-i+1);
//                    break;
//                }
//            }
//        }
//        if(res == INT_MAX) return 0;
//        return res;
//    }
//};