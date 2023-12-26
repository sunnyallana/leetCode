/*
Given a 2D board containing 'X' and 'O' (as characters), capture all regions surrounded by 'X'. A region is captured if it is surrounded by 'X' on all sides.

The algorithm should modify the board in-place, flipping all 'O's that are not surrounded by 'X' to 'X', while keeping the boundaries and 'X's unchanged.

In summary, the task is to identify and flip the regions of 'O's that are not surrounded by 'X' on all sides within the 2D board.
*/

#include <iostream>
using namespace std;

bool isSafe(int receiveCurrentRow, int receiveCurrentColumn, int receiveNumberRows, int receiveNumberColumns, char** receiveRegionMap){
    return ((receiveCurrentRow >= 0 && receiveCurrentRow < receiveNumberRows) && 
        (receiveCurrentColumn >= 0 && receiveCurrentColumn < receiveNumberColumns) &&
        receiveRegionMap[receiveCurrentRow][receiveCurrentColumn] == '0');
}


void sendDfsCalls(int receiveCurrentRow, int receiveCurrentColumn, int receiveNumberRows, int receiveNumberColumns, char** receiveRegionMap, char** receiveVisitedRegion){
    receiveVisitedRegion[receiveCurrentRow][receiveCurrentColumn] = 'V';
    receiveRegionMap[receiveCurrentRow][receiveCurrentColumn] = 'V';

    if(isSafe(receiveCurrentRow+1, receiveCurrentColumn, receiveNumberRows, receiveNumberColumns, receiveRegionMap) && receiveVisitedRegion[receiveCurrentRow+1][receiveCurrentColumn] != 'V'){
        sendDfsCalls(receiveCurrentRow+1, receiveCurrentColumn, receiveNumberRows, receiveNumberColumns, receiveRegionMap, receiveVisitedRegion);
    }
    if(isSafe(receiveCurrentRow, receiveCurrentColumn+1, receiveNumberRows, receiveNumberColumns, receiveRegionMap) && receiveVisitedRegion[receiveCurrentRow][receiveCurrentColumn+1] != 'V'){
        sendDfsCalls(receiveCurrentRow, receiveCurrentColumn+1, receiveNumberRows, receiveNumberColumns, receiveRegionMap, receiveVisitedRegion);
    }
    if(isSafe(receiveCurrentRow-1, receiveCurrentColumn, receiveNumberRows, receiveNumberColumns, receiveRegionMap) && receiveVisitedRegion[receiveCurrentRow-1][receiveCurrentColumn] != 'V'){
        sendDfsCalls(receiveCurrentRow-1, receiveCurrentColumn, receiveNumberRows, receiveNumberColumns, receiveRegionMap, receiveVisitedRegion);
    }
    if(isSafe(receiveCurrentRow, receiveCurrentColumn-1, receiveNumberRows, receiveNumberColumns, receiveRegionMap) && receiveVisitedRegion[receiveCurrentRow][receiveCurrentColumn-1] != 'V'){
        sendDfsCalls(receiveCurrentRow, receiveCurrentColumn-1, receiveNumberRows, receiveNumberColumns, receiveRegionMap, receiveVisitedRegion);
    }

    return;
}

void surroundRegions(int receiveNumberRows, int receiveNumberColumns, char** receiveRegionMap){
    char** visitedRegion = new char*[receiveNumberRows];
    for(int i = 0; i < receiveNumberRows; i++){
        visitedRegion[i] = new char[receiveNumberColumns];
    }

    for(int i = 0; i < receiveNumberRows; i++){
        for(int j = 0; j < receiveNumberColumns; j++){
            if(receiveRegionMap[i][0] == '0'){
               sendDfsCalls(i, 0, receiveNumberRows, receiveNumberColumns, receiveRegionMap, visitedRegion); 
            }
            else if(receiveRegionMap[i][receiveNumberColumns-1] == '0'){
                sendDfsCalls(i, receiveNumberColumns-1, receiveNumberRows, receiveNumberColumns, receiveRegionMap, visitedRegion);
            }
            else if(receiveRegionMap[0][j] == '0'){
                sendDfsCalls(0, j, receiveNumberRows, receiveNumberColumns, receiveRegionMap, visitedRegion);
            }
            else if(receiveRegionMap[receiveNumberRows-1][j] == '0'){
                sendDfsCalls(receiveNumberRows-1, j, receiveNumberRows, receiveNumberColumns, receiveRegionMap, visitedRegion);
            }
        }
    }

    for(int i = 0; i < receiveNumberRows; i++){
        for(int j = 0; j < receiveNumberColumns; j++){
            if(receiveRegionMap[i][j] == '0'){
                receiveRegionMap[i][j] = 'X';
            }
        }
    }

    for(int i = 0; i < receiveNumberRows; i++){
        for(int j = 0; j < receiveNumberColumns; j++){
            if(receiveRegionMap[i][j] == 'V'){
                receiveRegionMap[i][j] = '0';
            }
        }
    }
}

void printRegion(int receiveNumberRows, int receiveNumberColumns, char** receiveRegion){
    for(int i = 0; i < receiveNumberRows; i++){
        for(int j = 0; j < receiveNumberColumns; j++){
            cout << receiveRegion[i][j] << " ";
        }
        cout << endl;
    }
}

int main(void){
    int rows = 4;
    int columns = 5;

    char** region = new char* [rows];
    for(int i = 0 ; i < rows; i++){
        region[i] = new char[columns];
    }

    region[0][0] = 'X';
    region[0][1] = 'X';
    region[0][2] = 'X';
    region[0][3] = 'X';
    region[0][4] = 'X';

    region[1][0] = 'X';
    region[1][1] = '0';
    region[1][2] = '0';
    region[1][3] = 'X';
    region[1][4] = '0';

    region[2][0] = 'X';
    region[2][1] = '0';
    region[2][2] = 'X';
    region[2][3] = '0';
    region[2][4] = '0';

    region[3][0] = 'X';
    region[3][1] = 'X';
    region[3][2] = 'X';
    region[3][3] = '0';
    region[3][4] = 'X';

    printRegion(rows, columns, region);

    surroundRegions(rows, columns, region);

    cout << endl;
    
    printRegion(rows, columns, region);
}