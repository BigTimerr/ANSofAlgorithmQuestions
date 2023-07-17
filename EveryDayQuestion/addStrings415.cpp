//
// Created by ruetrash on 2023/7/17.
//

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

using namespace std;


class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int add = 0;
        string s = "";
        while(i >= 0 || j >= 0 || add!=0){
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x +y + add;
            s.push_back('0'+result % 10);
            add = result / 10;
            i--;
            j--;
        }

        reverse(s.begin(), s.end());
        return s;

    }
};