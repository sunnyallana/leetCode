#include <stack>
#include <string>

class Solution {
public:
    bool isValid(string s) {
        stack<char> openingBrackets;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                openingBrackets.push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                if (openingBrackets.empty()) {
                    return false;
                }

                char matchingOpening = openingBrackets.top();
                openingBrackets.pop();

                if ((c == ')' && matchingOpening != '(') ||
                    (c == '}' && matchingOpening != '{') ||
                    (c == ']' && matchingOpening != '[')) {
                    return false;
                }
            }
        }

        return openingBrackets.empty();
    }
};
