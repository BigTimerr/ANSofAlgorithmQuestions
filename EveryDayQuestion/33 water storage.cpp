//
// Created by ruetrash on 2023/5/22.
//
# include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int mx = *max_element(vat.begin(), vat.end());  //首先查看所有水缸蓄水量的最大值
        if(mx == 0){                                             //如果最大值都是0， 那么直接返回0
            return 0;
        }

        int ans = INT_MAX;
        int n = bucket.size();
        for (int x = 1; x < mx; ++x) {
            int y = 0;
            for (int i = 0; i < n; ++i) {
                y+= max(0,  int(vat[i] / x) + 1 - bucket[i]);
            }
            ans = min(ans, x + y);
        }
        return ans;
    }
};