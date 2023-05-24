//
// Created by ruetrash on 2023/5/10.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0;
        int n = nums.size();
        int blue = n-1;

        for(int i = 0; i < n; i++){
            while(i < blue && nums[i]==2){
                swap(nums[i], nums[blue]);
                --blue;
            }
            if(nums[i]==0){
                swap(nums[i], nums[red]);
                red++;
            }

        }
        }
};


