//
// Created by ruetrash on 2023/8/8.
//
# include <vector>
# include <iostream>
# include <algorithm>
# include <cmath>

using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int positiveSum = 0, positiveMax = 0;
        int negativeSum = 0, negativeMin = 0;

        for (auto num: nums) {
            positiveSum += num;
            positiveMax = max(positiveSum, positiveMax);
            positiveSum = max(positiveSum, 0);

            negativeSum += num;
            negativeMin = min(negativeMin, negativeSum);
            negativeSum = min(0, negativeSum);
        }

        return max(positiveMax, -negativeMin);

    }
};



