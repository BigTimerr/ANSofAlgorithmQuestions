//
// Created by ruetrash on 2023/7/23.
//

# include <vector>
# include <iostream>
# include <algorithm>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for(int bill : bills){
            if (bill == 5){
                five ++;
            }
            else if (bill == 10){
                if(five>0){
                    five--;
                    ten++;
                }
                else{
                    return false;
                }
            } else if(bill == 20){
                if(ten > 0){
                    if(five > 0){
                        ten--;
                        five--;
                    } else return false;
                }else{
                    if(five >= 3){
                        five -= 3;
                    } else return false;
                }
            }
        }
        return true;
    }
};