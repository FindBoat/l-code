#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        if (num == 0) return "";
        int base = 10;
        while (num % base == 0) base *= 10;
        if (base > num) {
            int first = (num / (base / 10)) % 10;
            string one, five, ten;
            if (base == 10) {
                one = "I";
                five = "V";
                ten = "X";
            } else if (base == 100) {
                one = "X";
                five = "L";
                ten = "C";
            } else if (base == 1000) {
                one = "C";
                five = "D";
                ten = "M";
            } else {
                one = "M";
            }
            switch (first) {
            case 1:
                return one;
            case 2:
                return one + one;
            case 3:
                return one + one + one;
            case 4:
                return one + five;
            case 5:
                return five;
            case 6:
                return five + one;
            case 7:
                return five + one + one;
            case 8:
                return five + one + one + one;
            default:
                return one + ten;
            }
        } else {
            int cur = num % base;
            int pre = num - cur;
            return intToRoman(pre) + intToRoman(cur);
        }
    }
};
