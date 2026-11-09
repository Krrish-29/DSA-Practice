// 4084. Last Visited Cell in a Directional Grid
class Solution {
private:
    void resolvePos(int &x,int &y,int& prevX,int& prevY,char& move){
        if(move == 'L') y = prevY - 1;
        else if(move == 'R') y = prevY + 1;
        else if(move == 'U') x = prevX - 1;
        else x = prevX + 1;
    }
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        // based on the moves provided in the grid starting with 0,0
        // resolve the new coords and check whether the move is possible and is not seen
        // if its a valid move, change the current coords to it
        // else break and return the current coords we have 
        // and mark any new position seen 
        int m = grid.size(), n = grid[0].size(), size = m*n; 
        int currX = 0,currY = 0 ,nextX ,nextY;
        for(int i=0;i<size;i++){
            resolvePos(nextX, nextY, currX, currY,grid[currX][currY]);
            grid[currX][currY] = '#';
            if(nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || grid[nextX][nextY] == '#') break;
            currX = nextX;
            currY = nextY;

        }
        return {currX,currY};
    }
};