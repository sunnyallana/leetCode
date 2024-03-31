/*
IS PALINDROME NUMBER

Given an integer x, return true if x is a
palindrome
, and false otherwise.



Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.


Constraints:

-231 <= x <= 231 - 1


Follow up: Could you solve it without converting the integer to a string?


*/


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) { //Neither negative numbers can be zero nor the numbers that end with zero since the leading zero would be lost after calculating reverse 
            return false;
        }
        return x == reverse(x);
    }

    int reverse(int x) {
        int temp = 0;
        while (x != 0) {
            int lastDigit = x % 10;
            if (temp > INT_MAX / 10 || (temp == INT_MAX / 10 && lastDigit > 7))
                return 0;
            if (temp < INT_MIN / 10 || (temp == INT_MIN / 10 && lastDigit < -8))
                return 0;

            temp = temp * 10 + lastDigit;
            x /= 10;
        }
        return temp;
    }
};
