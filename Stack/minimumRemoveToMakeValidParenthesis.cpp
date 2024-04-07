#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<bool> remove(s.length(), false);
        
        stack<int> st;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    remove[i] = true;
                }
            }
        }
        
        while (!st.empty()) {
            remove[st.top()] = true;
            st.pop();
        }
        
        string result = "";
        for (int i = 0; i < s.length(); ++i) {
            if (!remove[i]) {
                result += s[i];
            }
        }        
        return result;
    }
};