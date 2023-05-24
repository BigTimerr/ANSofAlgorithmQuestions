//
// Created by ruetrash on 2023/5/13.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());

        int large = -1;
        for(int x : nums){
            if(s.count(-x)){
                large = max(large, x);
            }
        }
        return large;

    }
};

//int main() {
//    vector<int> nums = {-1,2,-3,3};
//    Solution solu = Solution();
//    int temp = solu.findMaxK(nums);
//    cout<<temp;
//
//}

