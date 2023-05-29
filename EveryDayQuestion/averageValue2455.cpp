//
// Created by ruetrash on 2023/5/29.
//

# include <vector>
# include <iostream>

using namespace std;

class Solution {
public:
    int averageValue(vector<int>& nums) {

        int sum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if((nums[i] % 3 == 0) && (nums[i] % 2 == 0)){
                count++;
                sum += nums[i];
            }
        }
        if(count==0) return 0;
        return int(sum/count);
    }

};