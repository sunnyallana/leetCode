#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> mapping;

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                char currentCharacter = board[i][j];
                if (currentCharacter != '.') {
                    if (!mapping.insert("Value: " + string(1, currentCharacter) + "Row: " + to_string(i)).second ||
                        !mapping.insert("Value: " + string(1, currentCharacter) + "Column: " + to_string(j)).second ||
                        !mapping.insert("Value: " + string(1, currentCharacter) + "Grid: " + to_string(i / 3) + "-" + to_string(j / 3)).second) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
