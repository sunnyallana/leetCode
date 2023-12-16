#include <iostream>
using namespace std;


bool isSafe(int** islandArray, bool** visitedArray, int currentRow, int currentColumn, int receiveRows, int receiveColumns) {
// Check if current coords identify an island, are within bounds, and have not been visited before
    return (currentRow >= 0 && currentRow < receiveRows &&
            currentColumn >= 0 && currentColumn < receiveColumns &&
            islandArray[currentRow][currentColumn] && !visitedArray[currentRow][currentColumn]);
}


void sendDfsCall(int** islandArray, bool** visitedArray, int currentRow, int currentColumn, int receiveRows, int receiveColumns){
    visitedArray[currentRow][currentColumn] = true;
    // If it is safe to go left, then go left
    if(isSafe(islandArray, visitedArray, currentRow, currentColumn+1, receiveRows, receiveColumns)){
        sendDfsCall(islandArray, visitedArray, currentRow, currentColumn+1, receiveRows, receiveColumns);
    }
    // If it is safe to go down, then go down
    if(isSafe(islandArray, visitedArray, currentRow+1, currentColumn, receiveRows, receiveColumns)){
        sendDfsCall(islandArray, visitedArray, currentRow+1, currentColumn, receiveRows, receiveColumns);
    }
    // If it is safe to go up, then go up
    if(isSafe(islandArray, visitedArray, currentRow-1, currentColumn, receiveRows, receiveColumns)){
        sendDfsCall(islandArray, visitedArray, currentRow-1, currentColumn, receiveRows, receiveColumns);
    }
    // If it is safe to go right, then go right
    if(isSafe(islandArray, visitedArray, currentRow, currentColumn-1, receiveRows, receiveColumns)){
        sendDfsCall(islandArray, visitedArray, currentRow, currentColumn-1, receiveRows, receiveColumns);
    }
    return;
}


int countIslands(int** islandArray, int receiveRows, int receiveColumns){
// Creating a dynamic visited array to keep track of visited coordinates
    bool** visitedArray = new bool*[receiveRows];
    for (int i=0 ; i<receiveRows ; ++i){
        visitedArray[i] = new bool[receiveColumns];
    }
// Initializing it with false for all coordinates
    for(int i=0; i<receiveRows; i++){
        for(int j=0; j<receiveColumns; j++){
            visitedArray[i][j] = false;
        }
    }
// Declaring and initializing count of islands with 0
    int islandCount = 0;
    for(int i=0; i<receiveRows; i++){
        for(int j=0; j<receiveColumns; j++){
// If there exits a non-visited island, increament the count and visit the whole island
            if(!visitedArray[i][j] && islandArray[i][j]){
                islandCount++;
                sendDfsCall(islandArray, visitedArray, i, j, receiveRows, receiveColumns);
            }
        }
    }
    return islandCount;
}



int main(void){
    int** island = new int*[4];
    for(int i=0; i<4; i++){
        island[i] = new int[4];
    }
    
    island[0][0] = 1;
    island[0][1] = 1;
    island[0][2] = 0;
    island[0][3] = 0;

    island[1][0] = 1;
    island[1][1] = 1;
    island[1][2] = 0;
    island[1][3] = 1;

    island[2][0] = 0;
    island[2][1] = 0;
    island[2][2] = 0;    
    island[2][3] = 0;

    island[3][0] = 0;
    island[3][1] = 1;
    island[3][2] = 0;
    island[3][3] = 0;

    cout << countIslands(island, 4, 4);   

    for(int i=0; i<4; i++){
        delete island[i];
    }
    delete island;
}