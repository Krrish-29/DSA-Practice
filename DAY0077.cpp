// 63. Unique Paths II
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<long>>dp(m,vector<long>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1) {
                    dp[i][j]=0;
                    continue;
                }
                if(i==0&&j==0) dp[i][j]=1;
                if(i>0) dp[i][j]+=dp[i-1][j]; 
                if(j>0)dp[i][j]+=dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};