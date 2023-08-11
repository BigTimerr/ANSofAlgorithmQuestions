//
// Created by ruetrash on 2023/8/11.
//

# include <vector>

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        if(n==1) return mat[0][0];

        int sum = 0;
        for (int i = 0; i < mat.size(); ++i) {
            sum += mat[i][i];
            sum += mat[i][n-1];
            n--;
        }

        if (mat.size() %2 ==1){
             n = mat.size();
            sum -= mat[n/2][n/2];
        }

        return sum;

    }
};