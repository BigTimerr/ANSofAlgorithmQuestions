//
// Created by ruetrash on 2023/6/26.
//


#include <iostream>

using namespace std;


class Solution {
public:
    int pivotInteger(int n) {
        int total = 0;
        for (int i = 1; i <= n; ++i) {
            total += i;
        }

        int pivot = 0;

        for (int i = 1; i <= n; ++i) {
            pivot += i;

            if (pivot == total){
                return i;
            }
            if (pivot > total){
                return -1;
            }
            total -= i;
        }
        return -1;
    }
};