#include <queue>
#include <iostream>
#include<vector>
using namespace std; 

// iostream, vector and queue are included
// Hint: use breadth-first-search

int secondsToBeRotten(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    
        int adjacentRow[] = {1, -1, 0, 0};
    int adjacentCol[]= {0, 0, 1, -1};
    
    queue<pair<pair<int,int>,int>> q;
    int RottenPath[row][col]; // Track the Rotten path
    int cntFreshApple = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(grid[i][j] == 2){
                q.push({{i,j},0});
                RottenPath[i][j] = 2;
            }else{
                RottenPath[i][j] = (grid[i][j])? 1: 0;
                cntFreshApple = (grid[i][j])? (cntFreshApple + 1) : (cntFreshApple);
            }
        }
    }
    
    int cnt = 0 ;// to see if rotten apple rottened all the fresh apple
    int timer = 0;
    while(!q.empty()){
        int rowTmp = q.front().first.first;
        int colTmp = q.front().first.second;
        int timeTmp = q.front().second;
        q.pop();
        timer = max(timer, timeTmp);
        //* Check for direction
        for(int i = 0; i < 4; i++){
            int nRow = rowTmp + adjacentRow[i];
            int nCol = colTmp + adjacentCol[i];
            if ( nRow >= 0 && nRow < row &&
                 nCol >= 0 && nCol < col &&
                 grid[nRow][nCol] == 1 && RottenPath[nRow][nCol] != 2){
                    RottenPath[nRow][nCol] = 2;
                    q.push({{nRow, nCol}, timeTmp + 1});
                    cnt ++;
                 }
        }
    }
    return (cnt == cntFreshApple)? timer : -1;
}

int main(){
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> grid(rows, vector<int>(cols));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) cin >> grid[i][j];
    }
    cout << secondsToBeRotten(grid);
}