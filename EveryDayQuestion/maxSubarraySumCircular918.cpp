//
// Created by ruetrash on 2023/7/24.
//

# include <vector>
# include <algorithm>
# include <iostream>

using namespace std;


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int preMax = 0, max_value = nums[0];
        int preMin = 0, min_value = nums[0];
        int sum = 0;
        for (const auto &num:nums) {
            preMax = max(preMax + num, num);
            max_value = max(preMax, max_value);

            preMin = min(preMin +num, num);
            min_value = min(preMin, min_value);

            sum = sum + num;
        }

        if(max_value < 0){
            return max_value;
        }else{
            return max(max_value, sum - min_value);
        }

    }
};


//int main(){
//    Solution solu = Solution();
//    vector<int> nums = {-1,-2,-3,-2};
//    int res = solu.maxSubarraySumCircular(nums);
//    cout << res;
//}