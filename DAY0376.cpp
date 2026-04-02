// 3418. Maximum Amount of Money Robot Can Earn
class Solution {
private:
    int m,n;
    vector<vector<vector<int>>>dp;
    int helper(vector<vector<int>>&coins,int i,int j,int neutralize){
        if(i==m-1&&j==n-1) {
            if(coins[i][j]<0&&neutralize<2) return 0;
            return coins[i][j];
        }
        if(dp[i][j][neutralize]!=INT_MIN) return dp[i][j][neutralize];
        int bottom=INT_MIN,right=INT_MIN;
        if(i+1<m){
            bottom=max(bottom,coins[i][j]+helper(coins,i+1,j,neutralize));
            if(coins[i][j]<0&&neutralize<2) bottom=max(bottom,helper(coins,i+1,j,neutralize+1));
        }
        if(j+1<n){
            right=max(right,coins[i][j]+helper(coins,i,j+1,neutralize));
            if(coins[i][j]<0&&neutralize<2) right=max(right,helper(coins,i,j+1,neutralize+1));
        }
        return dp[i][j][neutralize]=max(right,bottom);
    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
        m=coins.size();
        n=coins[0].size();
        dp.resize(m,vector<vector<int>>(n,vector<int>(3,INT_MIN)));
        return helper(coins,0,0,0);
    }
};