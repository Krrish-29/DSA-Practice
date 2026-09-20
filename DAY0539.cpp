// 4046. Minimum Cost Path With At Most K Turns
class Solution {
private:
    vector<vector<vector<vector<int>>>>dp;
    int m,n;
    vector<vector<int>>dirs = {{0,1},{1,0},{-1,0},{0,-1}};
    long long helper(vector<vector<int>>& grid,int turns,int x,int y,int dir){
        if(x == m-1 && y == n-1) return grid[x][y];
        if(dp[x][y][turns][dir+1]!=-1) return dp[x][y][turns][dir+1];
        long long cost=INT_MAX;
        int newX,newY;
        for(int i=0;i<4;i++){
            newX = x+dirs[i][0];
            newY = y+dirs[i][1];
            if(newX>=0 && newX<m && newY>=0 && newY<n){
                if(dir == -1 || dir == i) cost = min(cost,grid[x][y]+helper(grid,turns,newX,newY,i));
                else if(turns>0) cost = min(cost,grid[x][y]+helper(grid,turns-1,newX,newY,i));
            }
        }
        return dp[x][y][turns][dir+1]=cost;
    }
public:
    int minCost(vector<vector<int>>& grid, int k) {
        // simple 4d dp 
        // first using we need to recursively find the solution and then use memo to optimize
        // the main things are the current location represented by x and y and the current direction 
        // and as well as the number of turns left 
        // then we move in any one direction starting with -1 to explore all 4 next and if the direction move is same as prev then we do not reduce turns(as well when dir is -1) else reduce the turns 
        // also check if we have turns available before reducing or turning 
        // the representaion of left right up down is not important making sure the markings are consistent is important 
        m=grid.size();
        n=grid[0].size();
        dp.assign(m,vector<vector<vector<int>>>(n,vector<vector<int>>(k+1,vector<int>(4+1,-1))));
        int ans = helper(grid,k,0,0,-1);
        return ans==INT_MAX?-1:ans;
    }
};