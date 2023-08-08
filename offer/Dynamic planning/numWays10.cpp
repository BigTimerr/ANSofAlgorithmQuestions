//
// Created by ruetrash on 2023/8/8.
//

class Solution {
public:
    int numWays(int n) {
        if(n == 0) return 1;
        if(n <= 2) return n;

        int a = 1, b =1, c= 2;
        for (int i = 3; i <=n ; ++i) {

            a = b;
            b = c;
            c = (a+b) % 1000000007;

        }
        return c;

    }
};