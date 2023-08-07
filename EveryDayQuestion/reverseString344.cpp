//
// Created by ruetrash on 2023/8/7.
//
# include <vector>
# include <iostream>
# include <algorithm>


using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp = ' ';
        int n = s.size()-1;

        for(int i = 0; i<=n; i++, n--){
            temp = s[i];
            s[i] = s[n];
            s[n] = temp;
        }
    }
};

