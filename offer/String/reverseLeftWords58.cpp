//
// Created by ruetrash on 2023/8/1.
//

# include <string>

using namespace std;


class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string str(s.begin() + n, s.end());
        string newstr(s.begin(), s.begin()+n);
        str += newstr;
        return str;

    }
};