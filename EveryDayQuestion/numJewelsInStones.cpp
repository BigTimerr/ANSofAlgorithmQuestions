//
// Created by ruetrash on 2023/7/24.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> boxes;

        for (auto jewel: jewels) {
            boxes[jewel] = 1;
        }
        int res = 0;
        for (auto stone: stones) {
            if (boxes[stone] == 1){
                res++;
            }

        }
        return res;
    }
};