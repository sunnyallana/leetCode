#include <string>
#include <stack>
#include <cctype>

class Solution {
public:
    string makeGood(string s) {
        stack<char> charStack;
        
        for (char c : s) {
            if (!charStack.empty() && abs(charStack.top() - c) == 32) {
                charStack.pop();
            } else {
                charStack.push(c);
            }
        }
        
        string result;
        while (!charStack.empty()) {
            result = charStack.top() + result;
            charStack.pop();
        }
        
        return result;
    }
};
