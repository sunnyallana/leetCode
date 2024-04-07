#include <string>
#include <limits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        bool isPositive = true;
        long long result = 0;
        int i = 0;
        int n = s.length();

        // Step 1: Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Determine sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            isPositive = (s[i] == '+');
            i++;
        }

        // Step 3: Process digits
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // Check for overflow
            if (isPositive && result > INT_MAX) {
                return INT_MAX;
            } else if (!isPositive && -result < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        // Apply sign
        if (!isPositive) {
            result = -result;
        }

        // Convert long long int to int to match function's signature
        return static_cast<int>(result);
    }
};
