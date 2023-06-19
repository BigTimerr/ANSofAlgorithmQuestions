//
// Created by ruetrash on 2023/6/19.
//

#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_set>
#include <map>
#include <numeric>

using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        vector<int> v[3];
        for (int num:nums) {
            v[num % 3].push_back(num);
        }

        sort(v[1].begin(), v[1].end(),less<int>());
        sort(v[2].begin(), v[2].end(),less<int>());

        int total = accumulate(nums.begin(), nums.end(), 0);
        int remove = INT_MAX;

        if(total % 3 == 0){
            remove = 0;
        }else if (total % 3 == 1){
            if(v[1].size() >= 1){
                remove = min(remove, v[1][0]);
            }
            if (v[2].size() >= 2){
                remove = min(remove, v[2][0]+v[2][1]);
            }
        }else{
            if(v[1].size() >= 2){
                remove = min(remove, v[1][0]+v[1][1]);
            }
            if (v[2].size() >= 1){
                remove = min(remove, v[2][0]);
            }
        }

        return total - remove;
    }
};
