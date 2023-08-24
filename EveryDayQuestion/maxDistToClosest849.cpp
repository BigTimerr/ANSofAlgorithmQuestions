//
// Created by ruetrash on 2023/8/22.
//
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int left = 0;
        int right = 0;
        int res = 0;

        while(left < seats.size() && seats[left] == 0){
            left++;
        }
        res = max(res, left);
        while(left < seats.size()){
            right = left+1;
            while(right < seats.size() && seats[right] == 0){
                right++;
            }
            if (right == seats.size()){
                res = max(res, right - left - 1);
            }else{
                res = max(res, (right - left) / 2);
            }
            left = right;
        }
        return res;

    }
};