class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // Initialize the matrix with zeros and resize it to n x n dimensions
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int columnStart = 0, columnEnd = n - 1, rowStart = 0, rowEnd = n - 1;
        int count = 0;

        while (columnStart <= columnEnd && rowStart <= rowEnd) {
            // Fill the top row from left to right
            for (int i = columnStart; i <= columnEnd; i++) {
                matrix[rowStart][i] = ++count;
            }

            // Fill the rightmost column from top to bottom
            for (int i = rowStart + 1; i <= rowEnd; i++) {
                matrix[i][columnEnd] = ++count;
            }

            // Fill the bottom row from right to left
            if (rowStart != rowEnd) { // Avoid duplicate filling for odd-sized matrix
                for (int i = columnEnd - 1; i >= columnStart; i--) {
                    matrix[rowEnd][i] = ++count;
                }
            }

            // Fill the leftmost column from bottom to top
            if (columnStart != columnEnd) { // Avoid duplicate filling for odd-sized matrix
                for (int i = rowEnd - 1; i > rowStart; i--) {
                    matrix[i][columnStart] = ++count;
                }
            }

            rowStart++;
            rowEnd--;
            columnStart++;
            columnEnd--;
        }
        return matrix;
    }
};