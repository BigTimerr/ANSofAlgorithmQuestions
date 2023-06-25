//
// Created by ruetrash on 2023/6/25.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int res = INT_MIN;
        for (auto str: strs) {

            bool isDigit = true;

            for (auto s: str) {
                isDigit &= isdigit(s);
            }

            res = max(res, isDigit ? stoi(str):(int)str.size());

        }

        return res;
    }
};