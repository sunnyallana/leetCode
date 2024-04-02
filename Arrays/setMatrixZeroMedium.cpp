#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(); 
        bool zeroFirstRow = false, zeroFirstCol = false;
        
        // Check if the first row has any zero
        for(int j = 0; j < n; j++) {
            if(matrix[0][j] == 0) {
                zeroFirstRow = true;
                break;
            }
        }
        
        // Check if the first column has any zero
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) {
                zeroFirstCol = true;
                break;
            }
        }
        
        // Marking zeros in the first row and column
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // Setting zeros based on the markers in the first row and column
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Setting zeros for the first row and column if necessary
        if(zeroFirstRow) {
            for(int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        
        if(zeroFirstCol) {
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};