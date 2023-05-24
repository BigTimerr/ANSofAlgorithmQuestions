//
// Created by ruetrash on 2023/5/10.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void heapify(vector<int>& heap, int n, int i){
        int small = i; //初始化最小值为当前节点
        int left = 2*i+1;
        int right = 2*i+2;

        if(left<n && heap[left]<heap[small]){
            small = left;
        }
        if(right<n && heap[right]<heap[small]){
            small = right;
        }
        if(small != i){
            swap(heap[i], heap[small]);
            heapify(heap, n,small);
        }

    }

    void buildHeap(vector<int>& heap, int n){
        for(int i = (n/2)-1; i >= 0; i--){
            heapify(heap,n,i);
        }
    }


    int findKthLargest(vector<int>& nums, int k) {

        int size = nums.size();

        buildHeap(nums, size);

        for(int i=size-1;i>0;i--){
            swap(nums[0], nums[i]);
            heapify(nums, i ,0 );
        }

        return nums[k-1];
    }

};






