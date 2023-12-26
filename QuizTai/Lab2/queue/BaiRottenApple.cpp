#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// iostream, vector and queue are included
// Hint: use breadth-first-search

int secondsToBeRotten(vector<vector<int>>& grid) {
    
    int n = grid.size(); // row size
    int m = grid[0].size(); // columns size

    int Adjacentrow[] = {1, -1,0,0};
    int AdjacentCol[] = {0, 0, 1,-1};
    queue<pair<pair<int, int>, int> > q;

    int RottenPath[n][m];
    int cntFreshApple = 0;
    // push all rotten apple into the Queue
    for( int i = 0; i < n; i++){
        for( int j = 0; j < m; j++){
            if( grid[i][j] == 2){
                // rotten apple, push into the queue
                q.push({{i,j}, 0});
                RottenPath[i][j] = 2; 
                // set the time to 0 since it is rotten
            }else if ( grid[i][j] == 1){
                cntFreshApple++;
                RottenPath[i][j] = 1;
            }else{
                RottenPath[i][j] = 0; 
            }
        }
    }

    int cnt = 0; // to see if the rotten apple rotten all the fresh apples, cnt == cntFreshApple
    int time = 0;
    while ( !q.empty()){
        int Row = q.front().first.first;
        int Col = q.front().first.second;
        int timee = q.front().second;

        // pop the queue
        q.pop();
        time = max(timee, time); // take the longest time
        // checking the adjacent of the position of the pop apple
        for( int i = 0; i < 4; i++){
            int NRow = Row + Adjacentrow[i];
            int NCol = Col + AdjacentCol[i];

            // check the apple, make sure it valid and it is not a rotten apple
            if (NRow >= 0 && NRow < n &&
                NCol >=0 && NCol < m &&
                grid[NRow][NCol] == 1 && // apple indeed
                RottenPath[NRow][NCol] != 2){
                    RottenPath[NRow][NCol] = 2;
                    q.push({{NRow, NCol}, timee + 1});
                    cnt++;
                }
        }
    }
    return ( cnt == cntFreshApple)? time : -1;

}