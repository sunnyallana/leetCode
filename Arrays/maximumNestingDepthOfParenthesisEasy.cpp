#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        if(!s.length()) return 0;
        stack<char> st;
        int maxDepth = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                st.push(s[i]);
                maxDepth = max(maxDepth, (int)st.size());
            } else if(s[i] == ')') {
                st.pop();
            }
        }
        return maxDepth;
    }
};