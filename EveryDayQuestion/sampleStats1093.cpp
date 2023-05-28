//
// Created by ruetrash on 2023/5/28.
//

#include <iostream>
# include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int n = count.size();
        int minimum = -1;
        int maximum = 256;

        long long total = 0;
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
        if(maximum == 256){
            maximum=0;
        }
        ans.push_back(double(minimum));
        ans.push_back(double(maximum));
        if (numsCount == 0){
            ans.push_back(0.0);
        }
        else{
            ans.push_back(double(total) / numsCount);
        }



        int nums = 0 ;
        int left = (numsCount + 1) / 2;
        int right = (numsCount + 2) / 2;
        for (int i = 0; i < n; ++i) {
            if (nums < right && nums + count[i] >= right) {
                median += i;
            }
            if (nums < left && nums + count[i] >= left) {
                median += i;
            }
            nums += count[i];
        }
        median = median / 2.0;
        ans.push_back(median);



        ans.push_back(double(mode.first));

        return ans;


    }
};

//int main(){
//    vector<int> count = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//    Solution solu = Solution();
//    auto res = solu.sampleStats(count);
//
//    for (double &x:res) {
//        cout<<x<<" ";
//    }
//}