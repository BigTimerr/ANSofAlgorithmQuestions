//
// Created by ruetrash on 2023/7/26.
//

# include <vector>
# include <unordered_map>
# include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        int i = 0, j = n-1;
        while (i<j){
            if (numbers[i] + numbers[j] < target){
                i++;
            }else if(numbers[i] + numbers[j] > target){
                j--;
            }else{
                return {i+1, j+1};
            }
        }
        return {};
    }
};