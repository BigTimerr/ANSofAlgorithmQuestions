//
// Created by ruetrash on 2023/8/8.
//

class Solution {
public:
    int fib(int n) {
        int Mod = 1e9 + 7;
        if (n<2){
            return n;
        }

        int a = 0, b = 0, c = 1;

        for (int i = 2; i <= n; ++i) {
            a = b;
            b = c;
            c = (a+b) % Mod;
        }
        return c;
    }
};