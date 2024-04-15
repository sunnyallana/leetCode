#include <iostream>
#include <ctime>
using namespace std;

void printMazePath(int** mazeVisited, int receiveRows, int receiveColumns){
    for(int i = 0; i < receiveRows; i++){
        for(int j = 0; j < receiveColumns; j++){
            cout << mazeVisited[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int** mazeGrid, int** mazeVisited, int currentRow, int currentColumn, int receiveRows, int receiveColumns){
    return ((currentRow >= 0 && currentRow < receiveRows) && (currentColumn >= 0 && currentColumn < receiveColumns) 
        && mazeGrid[currentRow][currentColumn] && !mazeVisited[currentRow][currentColumn]);
}

bool dfsCalls(int** mazeGrid, int** mazeVisited, int currentRow, int currentColumn, int receiveRows, int receiveColumns){
    // Mark the current coords as visited
    mazeVisited[currentRow][currentColumn] = 1;
    // Did we reach the destination?
    if(currentRow == receiveRows-1 && currentColumn == receiveColumns-1 && mazeGrid[currentRow][currentColumn]){
        return true;
    }
    else{
        // If not, then where can we go from here?
        // If we can go somewhere, send dfs calls for those coords and check if that leads to the solution. If yes, mozel tov. Else, backtrack
        if(isSafe(mazeGrid, mazeVisited, currentRow+1, currentColumn, receiveRows, receiveColumns)){
            if(dfsCalls(mazeGrid, mazeVisited, currentRow+1, currentColumn, receiveRows, receiveColumns)){
                return true;
            }            
            mazeVisited[currentRow+1][currentColumn] = 0;
        }
        if(isSafe(mazeGrid, mazeVisited, currentRow-1, currentColumn, receiveRows, receiveColumns)){
            if(dfsCalls(mazeGrid, mazeVisited, currentRow-1, currentColumn, receiveRows, receiveColumns)){
                return true;
            }        
            mazeVisited[currentRow-1][currentColumn] = 0;
        }
        if(isSafe(mazeGrid, mazeVisited, currentRow, currentColumn+1, receiveRows, receiveColumns)){
            if(dfsCalls(mazeGrid, mazeVisited, currentRow, currentColumn+1, receiveRows, receiveColumns)){
                return true;
            }        
            mazeVisited[currentRow][currentColumn+1] = 0;
        }
        if(isSafe(mazeGrid, mazeVisited, currentRow, currentColumn-1, receiveRows, receiveColumns)){
            if(dfsCalls(mazeGrid, mazeVisited, currentRow, currentColumn-1, receiveRows, receiveColumns)){
                return true;
            }            
            mazeVisited[currentRow][currentColumn-1] = 0;
        }
        mazeVisited[currentRow][currentColumn] = 0;
        return false;
    }
}

void findPathToDestination(int** mazeGrid, int receiveRows, int receiveColumns){
    int** mazeVisited = new int*[receiveRows];
    for(int i = 0; i < receiveRows; i++){
        mazeVisited[i] = new int [receiveColumns];
    }
    for(int i = 0; i < receiveRows; i++){
        for(int j = 0; j < receiveColumns; j++){
            mazeVisited[i][j] = 0;
        }
    }

    cout << "MAZE GRID:" << endl;
    printMazePath(mazeGrid, receiveRows, receiveColumns);

    cout << "MAZE SOLUTION: " << endl;
    if(dfsCalls(mazeGrid, mazeVisited, 0, 0, receiveRows, receiveColumns)){
        printMazePath(mazeVisited, receiveRows, receiveColumns);
        return;
    }
    cout << "No solution exists" << endl;
}

int main(void){
    int** mazeGrid = new int* [4];
    for(int i = 0; i < 4; i++){
        mazeGrid[i] = new int [4];
    }

    mazeGrid[0][0] = 1;
    mazeGrid[0][1] = 1;
    mazeGrid[0][2] = 0;
    mazeGrid[0][3] = 0;
    mazeGrid[1][0] = 1;
    mazeGrid[1][1] = 1;
    mazeGrid[1][2] = 1;
    mazeGrid[1][3] = 1;
    mazeGrid[2][0] = 0;
    mazeGrid[2][1] = 1;
    mazeGrid[2][2] = 0;
    mazeGrid[2][3] = 1;
    mazeGrid[3][0] = 0;
    mazeGrid[3][1] = 0;
    mazeGrid[3][2] = 0;
    mazeGrid[3][3] = 1;

    findPathToDestination(mazeGrid, 4, 4);    
}
