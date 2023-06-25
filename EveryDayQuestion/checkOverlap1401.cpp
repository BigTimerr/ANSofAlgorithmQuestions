//
// Created by ruetrash on 2023/6/25.
//
# include <vector>
#include <iostream>
using namespace std;


class Solution {
public:

    int f(int xCenter, int x1, int x2){
        if (xCenter >= x1 && xCenter <= x2){
            return 0;
        }else if (xCenter < x1){
            return x1 - xCenter;
        }else{
            return xCenter - x2;
        }
    }

    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int a = f(xCenter, x1, x2);
        int b = f(yCenter, y1 ,y2);

        if ((a*a + b*b) <= radius * radius){
            return true;
        }

        return false;


    }
};