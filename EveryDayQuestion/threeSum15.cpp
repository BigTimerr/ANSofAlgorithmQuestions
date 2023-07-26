//
// Created by ruetrash on 2023/7/25.
//

# include <vector>
# include <algorithm>
# include <queue>
# include <unordered_map>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n-2; ++i) {
            if(i && nums[i] == nums[i-1]){
                continue;
            }

            int j = i+1, k = n-1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] < 0){
                    j++;
                }
                else if(nums[i] + nums[j] + nums[k] > 0){
                    k--;
                }
                else{
                    res.push_back({nums[i], nums[j++], nums[k--]});
                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                    while(j<k && nums[k] == nums[k+1]){
                        k--;
                    }
                }
            }

        }
        return res;
    }
};