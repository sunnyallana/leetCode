#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int total = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int currentValue = romanValues[s[i]];

            if (i < n - 1 && romanValues[s[i]] < romanValues[s[i + 1]]) {
                total -= currentValue;
            } else {
                total += currentValue;
            }
        }

        return total;
    }
};
