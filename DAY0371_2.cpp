// 3882. Minimum XOR Path in a Grid
class Solution {
private:
    int m,n;
    vector<vector<vector<int>>>dp;
    int helper(vector<vector<int>>& grid,int i,int j,int xorVal){
        if(i==m-1&&j==n-1) return xorVal^grid[i][j];
        if(dp[i][j][xorVal]!=-1) return dp[i][j][xorVal];
        int down=INT_MAX,right=INT_MAX;
        if(i<m-1){
            down=helper(grid,i+1,j,grid[i][j]^xorVal);
        }
        if(j<n-1){
            right=helper(grid,i,j+1,grid[i][j]^xorVal);
        }
        return dp[i][j][xorVal]=min(down,right);
    }
public:
    int minCost(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        dp.resize(m,vector<vector<int>>(n,vector<int>(1024,-1)));
        return helper(grid,0,0,0);
    }
};