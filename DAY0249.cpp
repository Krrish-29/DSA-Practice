// 2435. Paths in Matrix Whose Sum Is Divisible by K
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        const int MOD=1e9+7;
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k,0)));
        dp[0][0][grid[0][0]%k]++;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int s=0;s<k;s++){
                    if(dp[i][j][s]==0) continue;
                    if(i+1<m){
                        int state=(s+grid[i+1][j])%k;
                        dp[i+1][j][state]=(dp[i+1][j][state]+dp[i][j][s])%MOD;
                    }
                    if(j+1<n){
                        int state=(s+grid[i][j+1])%k;
                        dp[i][j+1][state]=(dp[i][j+1][state]+dp[i][j][s])%MOD;
                    }
                }
            }
        }
        return dp[m-1][n-1][0];
    }
};