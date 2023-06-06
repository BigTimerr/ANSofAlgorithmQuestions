//
// Created by ruetrash on 2023/6/6.
//

#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_set>
#include <map>

using namespace std;


class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> cnt;

        for (auto val: grid) {
            cnt[val]++;
        }

        int res = 0;

        for (int j = 0; j < grid.size(); ++j) {
            vector<int> arr;
            for (int i = 0; i < grid.size(); ++i) {
                arr.emplace_back(grid[i][j]);
            }
            if(cnt.find(arr) != cnt.end()){
                res+=cnt[arr];
            }

        }
        return res;
    }
};