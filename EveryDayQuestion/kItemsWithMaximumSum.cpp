//
// Created by ruetrash on 2023/7/5.
//
#include <iostream>

using namespace std;
class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if(k==0) return 0;
        else if(k<=numOnes) return k;
        else if(k<=numOnes+numZeros) return numOnes;
        else if(k<=numOnes+numZeros+numNegOnes) return numOnes-(k-numZeros-numOnes);
        return 0;
    }
};

int main(){
    int numOnes = 6, numZeros = 6, numNegOnes = 6, k = 13;
    Solution solution = Solution();

    int res = solution.kItemsWithMaximumSum(numOnes, numZeros, numNegOnes, k);
    cout<<res;
}