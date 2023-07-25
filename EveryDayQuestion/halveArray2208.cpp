//
// Created by ruetrash on 2023/7/25.
//

# include <vector>
# include <algorithm>
# include <iostream>
# include <queue>

using namespace std;

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum = 0.0;
        double sum_half = 0.0;
        int i =0;
        for (auto num:nums) {
            double temp = (double)num;
            pq.emplace(temp);
            sum += temp;
        }
        while(sum_half < sum / 2){
            double a = pq.top();
            pq.pop();
            a = a/2;
            sum_half += a;
            pq.emplace(a);
            i++;
        }
    return i;
    }
};

//int main(){
//    vector<int> nums = {32,98,23,14,67,40,26,9,96,96,91,76,4,40,42,2,31,13,16,37,62,2,27,25,100,94,14,3,48,56,64,59,33,10,74,47,73,72,89,69,15,79,22,18,53,62,20,9,76,64};
//    Solution solution = Solution();
//    int res = solution.halveArray(nums);
//    cout << res ;
//}