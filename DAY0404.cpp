// 3742. Maximum Path Score in a Grid
class Solution {
private:
    vector<vector<vector<int>>>dp;
    int m,n;
    int totalCost;
    int traverse(vector<vector<int>>& grid,int i,int j,int c){
        if(i>=m||j>=n) return INT_MIN;
        int cost=c+(grid[i][j]!=0);
        if(cost>totalCost) return INT_MIN;
        if(i==m-1&&j==n-1) return grid[i][j];
        if(dp[i][j][c]!=-1) return dp[i][j][c];
        int right=traverse(grid,i,j+1,cost);
        int down=traverse(grid,i+1,j,cost);
        int maxScore=max(right,down);
        if(maxScore==INT_MIN) return dp[i][j][c]=INT_MIN;
        return dp[i][j][c]=grid[i][j]+maxScore;
    }
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m=grid.size();n=grid[0].size();totalCost=k;
        dp.resize(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        int ans= traverse(grid,0,0,grid[0][0]!=0);
        return ans==INT_MIN?-1:ans;
    }
};