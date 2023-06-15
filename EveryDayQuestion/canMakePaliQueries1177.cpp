//
// Created by ruetrash on 2023/6/15.
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
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int q = queries.size();

        vector<array<int, 26>> sum(n+1);

        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i];
            sum[i + 1][s[i] - 'a'] ^= 1;
        }

        vector<bool> ans(q);
        for (int i = 0; i < q; ++i) {
            auto& query = queries[i];
            int left = query[0], right = query[1], k = query[2], m = 0;
            for (int j = 0; j < 26; ++j) {
                m += (sum[right+1][j] ^ sum[left][j]);
            }
            ans[i] = m/2 <= k;
        }
        return ans;
    }
};