class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Initialize the longest common prefix as the first string in the vector, so that we can compare it with the rest of the strings in the vector
        string longestCommonPrefix = strs[0]; 
        for (int i = 1; i < strs.size(); i++) {
            // Compare the longest common prefix with the current string in the vector
            int j = 0;
            // The condition is that the index is less than the size of the longest common prefix and the current string in the vector, and the characters are the same
            while (j < longestCommonPrefix.size() && j < strs[i].size() && longestCommonPrefix[j] == strs[i][j]) {
                j++;
            }
            // Update the longest common prefix
            longestCommonPrefix = longestCommonPrefix.substr(0, j);
        }
        return longestCommonPrefix;
    }
};