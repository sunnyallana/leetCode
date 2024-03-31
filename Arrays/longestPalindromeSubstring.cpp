#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "")
            return "";

        string maxSubstring = s.substr(0, 1); // Initialize maxSubstring with the first character of s

        for(int i = 0; i < s.length(); i++){
            string stringOdd = expandAroundCenter(s, i, i); // Expand around center for odd-length palindrome
            string stringEven = expandAroundCenter(s, i, i + 1); // Expand around center for even-length palindrome

            if (stringOdd.length() > maxSubstring.length()){
                maxSubstring = stringOdd;
            }
            if (stringEven.length() > maxSubstring.length()){
                maxSubstring = stringEven;
            }
        }
        return maxSubstring;
    }

private:
    string expandAroundCenter(const string& s, int leftBound, int rightBound){
        while(leftBound >= 0 && rightBound < s.length() && s[leftBound] == s[rightBound]){
            leftBound--;
            rightBound++;
        }
        return s.substr(leftBound + 1, rightBound - leftBound - 1);
    }
};
