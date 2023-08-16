//
// Created by ruetrash on 2023/8/16.
//

# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> friends(n, 0);
        int ball = 0;
        for (int j = 0; j < n ; ++j) {
            ball = (j*k+ball) % n;
            if (friends[ball] != 0) break;
            else{friends[ball] =1;}
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (friends[i] ==0){
                ans.push_back(i+1);
            }
        }
        return ans;
        }
};