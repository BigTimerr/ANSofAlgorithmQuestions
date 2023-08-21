//
// Created by ruetrash on 2023/8/20.
//
# include <vector>
# include <algorithm>
# include <iostream>

using namespace std;

class Solution {
public:

    int N;
    int n;
    int maxSizeSlices(vector<int>& slices) {
        N = slices.size();
        n = N/3;
        return max(maxSizeSlices(slices, 0, N-1), maxSizeSlices(slices, 1, N));
    }

private:
    int maxSizeSlices(vector<int>& slices, int start, int end){
        vector<vector<int>> dp(N, vector<int>(n+1, 0));


//        for (int i = start + 2; i < end; ++i) {
//            dp[i][j]
//        }

    }
};