//
// Created by ruetrash on 2023/6/4.
//

#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> ans(queries.size());
        unordered_set<char> vowel{'a', 'e', 'i', 'o', 'u'};
        vector<int> trueTable(n+1, 0);

        for (int i = 0; i < n; ++i) {
            string str = words[i];
            if (vowel.count(str.front()) && vowel.count(str.back())){
                trueTable[i+1] = trueTable[i] + 1;
            }else{
                trueTable[i+1] = trueTable[i];
            }

        }

        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            ans[i] = trueTable[end+1] - trueTable[start];

        }

        return ans;
    }
};