#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        
        unordered_map<char, char> mapping;
        unordered_map<char, bool> used;
        
        for (int i = 0; i < s.size(); ++i) {
            char sChar = s[i];
            char tChar = t[i];
            
            if (mapping.find(sChar) == mapping.end()) {
                if (used[tChar]) return false;
                mapping[sChar] = tChar;
                used[tChar] = true;
            } else {
                if (mapping[sChar] != tChar) return false;
            }
        }
        
        return true;
    }
};