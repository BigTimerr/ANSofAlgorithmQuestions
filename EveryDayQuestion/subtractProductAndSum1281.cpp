//
// Created by ruetrash on 2023/8/9.
//

# include <iostream>
# include <vector>
# include <iostream>

using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {

        if (n == 0){
            return 0;
        }

        long long mul = 1;
        long long sum = 0;

        while(n > 0){
            int temp = n % 10;
            mul = mul * temp;
            sum = sum + temp;
            n = n /10;
        }

        return mul - sum;

    }
};
