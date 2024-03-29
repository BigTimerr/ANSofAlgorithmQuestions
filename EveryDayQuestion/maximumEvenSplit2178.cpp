//
// Created by ruetrash on 2023/7/6.
//

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {

        vector<long long> res;

        if(finalSum % 2 != 0){return res;}

        for (int i = 2; i <= finalSum; i+=2) {
            res.push_back(i);
            finalSum -= i;
        }
        res.back() += finalSum;
        return res;
    }
};