//
// Created by ruetrash on 2023/5/23.
//
# include <vector>
# include <queue>
# include <numeric>
# include <algorithm>
# include <iostream>
# include <unordered_map>

using namespace std;

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int n = count.size();
        int minimum = -1;
        int maximum = 256;

        long long int total = 0;
        int numsCount = 0;

        double median = 0;

        pair<int, int> mode = {-1, -1};

        for (int i = 0; i < n; ++i) {
            if(count[i] != 0){
                maximum = i;
                if (minimum == -1){
                    minimum = i;
                }
                total = total + i * count[i];
                numsCount = numsCount + count[i];

                if (count[i] > mode.second){
                    mode.first = i;
                    mode.second = count[i];
                }

            }

        }
        vector<double> ans;
        ans.push_back(double(minimum));
        ans.push_back(double(maximum));
        ans.push_back(double(total) / numsCount);


        int nums = 0 ;

        if (numsCount % 2 == 0) {
            int leftmidlenth = numsCount / 2;
            double leftmidvalue = 0;
            double rightmidvalue = 0;
            for (int i = 0; i < count.size(); i++) {
                if (leftmidlenth - count[i] > 0) {
                    leftmidlenth -= count[i];
                } else {
                    leftmidvalue = i;
                    if (leftmidlenth - count[i] == 0) {
                        rightmidvalue = i + 1;
                    } else {
                        rightmidvalue = i;
                    }

                    median = (leftmidvalue + rightmidvalue) / 2;

                    break;
                }
            }
        } else {
            int midlength = numsCount / 2 + 1;

            for (int i = 0; i < count.size(); i++) {
                if (midlength - count[i] > 0) {
                    midlength -= count[i];
                } else {
                    median = i;
                    break;
                }
            }
        }

        ans.push_back(median);


        ans.push_back(double(mode.first));
        return ans;


    }
};

//int main(){
//    vector<int> count = {0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//
//    Solution solution = Solution();
//    auto res = solution.sampleStats(count);
//    for (auto x: res) {
//        cout<< x<<endl;
//
//    }
//}
