//
// Created by ruetrash on 2023/8/13.
//

# include <vector>
# include <iostream>
# include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(nums1);
        int i = 0, j = 0;
        int flag = 0;

        while(i < m && j < n){
            if (temp[i] <= nums2[j]){
                nums1[flag++] = temp[i++];
            }else{
                nums1[flag++] = nums2[j++];
            }
        }
        if (i == m){
            for(;j<n;j++){
                nums1[flag++] = nums2[j];
            }
        }
        if(j == n){
            for(;i<m;i++){
                nums1[flag++] = temp[i];
            }
        }


    }
};