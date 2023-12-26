#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

class node {
public:
    int x, y;
    int dir;
    node(int i, int j)
    {
        x = i;
        y = j;
  
        // Initially direction
        // set to 0
        dir = 0;
    }
};

bool canEatFood(int maze[5][5], int fx, int fy){
    /*TODO*/
    stack<node> Stacking;
    vector< vector<bool>> visited( 5, vector<bool> ( 5, true));
    int x = 0; // x- coordinate
    int y = 0;  // y-coordinate
    node temp(x, y);
    Stacking.push(temp);
    while( !Stacking.empty()){
        temp = Stacking.top();
        int d = temp.dir;
        x = temp.x;
        y = temp.y;
        // dir ++ for latter loop 
        temp.dir++;
        Stacking.pop();
        Stacking.push(temp);

        if ( x == fx && y ==fy){
            return true;
        }
        if ( d == 0){ // up i - 1
            if ( x - 1 >= 0 && maze[x - 1][y] && visited[x-1][y]){
                node temper ( x - 1, y);
                visited[ x - 1][y] = false;
                Stacking.push(temper);
            }
        }else if ( d == 1){ //left j -1
            if ( y - 1 >=0 && maze[x][y-1] && visited[x][y - 1]){
                node temper (x, y-1);
                visited [x][y - 1] = false;
                Stacking.push(temper);
            }
        }else if ( d == 2){ //down i + 1
            if ( x + 1 < 5 && maze[ x + 1][y] && visited[x + 1][y]){
                node temper ( x+1, y);
                visited [x+1][y] = false;
                Stacking.push(temper);
            }
        }else if ( d == 3){ // right j + 1
            if ( y + 1 < 5 && maze[ x ][y+ 1] && visited[x ][y+1]){
                node temper ( x, y+1);
                visited [x][y+1] = false;
                Stacking.push(temper);
            }
        }else{
            visited[temp.x][temp.y] = true;
            Stacking.pop();
        }
    }
    return false;
}


int main(){
    // Maze matrix
    int maze[5][5] = {
        { 1, 0, 1, 1, 0 },
        { 1, 1, 1, 0, 1 },
        { 0, 1, 0, 1, 1 },
        { 1, 1, 1, 1, 0 },
        { 1, 0, 0, 1, 0 }
    };

    // Food coordinates
    int fx = 1, fy = 4;

    cout << canEatFood(maze, fx, fy);
}