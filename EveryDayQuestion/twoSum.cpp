//
// Created by ruetrash on 2023/7/25.
//
# include <vector>
# include <algorithm>
# include <iostream>
# include <set>
# include <unordered_map>
# include <iterator>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;

        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target-nums[i]);
            if(it != hashtable.end()){
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};