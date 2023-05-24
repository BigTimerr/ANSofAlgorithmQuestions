//
// Created by ruetrash on 2023/5/11.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        int len = len1 + len2;
        int left = -1, right = -1;
        int astart = 0, bstart = 0;

        for (int i = 0; i <= len/2; i++){
            left = right;
//            if((astart<len1 && bstart>=len2) || (astart<len1 && nums1[i]< nums2[i])){  //如果nums1还有数据并且nums2没数据，或，nums1和nums2都有数据但nums1数据小
//                right = nums1[astart++];
//            }else{
//                right = nums2[bstart++];
//            }

            if(astart<len1 && bstart<len2){
                if(nums1[astart]< nums2[bstart]){
                    right = nums1[astart++];
                }else{
                    right = nums2[bstart++];
                }
            }else if(astart>=len1){
                right = nums2[bstart++];
            }else{
                right = nums1[astart++];
            }
        }

        if(len % 2 == 0){
            return (left+right)/2.0;
        }else{
            return right*1.0;
        }

    }
};


