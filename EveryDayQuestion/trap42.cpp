//
// Created by ruetrash on 2023/7/23.
//
# include <vector>
# include <iostream>
# include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> max_left(n, 0);
        vector<int> max_right(n,0);
        for (int i = 1; i < n-1; ++i) {
            max_left[i] = max(height[i-1], max_left[i-1]);
        }
        for (int i = n-2; i > 0; --i) {
            max_right[i] = max(height[i+1], max_right[i+1]);
        }

        int res = 0;

        for (int i = 1; i < n; ++i) {
            int min_value = min(max_left[i], max_right[i]);
            if (min_value > height[i]){
                res = res + min_value - height[i];
            }
        }
        return res;
    }
};

//int main(){
//    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
//    Solution solu = Solution();
//    int res = solu.trap(height);
//
//    cout << res;
//
//}