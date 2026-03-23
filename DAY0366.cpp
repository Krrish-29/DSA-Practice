// 1594. Maximum Non Negative Product in a Matrix
class Solution {
private:
    int m,n;
    vector<vector<pair<long long,long long>>>dp;
    pair<long long,long long> helper(vector<vector<int>>& grid,int i,int j){
        if(i==m-1&&j==n-1) return {grid[i][j],grid[i][j]};
        if(dp[i][j]!=make_pair(LLONG_MIN,LLONG_MIN)) return dp[i][j];
        long long maxVal=LLONG_MIN;
        long long minVal=LLONG_MAX;
        if(i+1<m){
            auto [downMax,downMin] = helper(grid,i+1,j);
            maxVal=max({maxVal,grid[i][j]*downMax,grid[i][j]*downMin});
            minVal=min({minVal,grid[i][j]*downMax,grid[i][j]*downMin});
        }
        if(j+1<n){
            auto [leftMax,leftMin] = helper(grid,i,j+1);
            maxVal=max({maxVal,grid[i][j]*leftMax,grid[i][j]*leftMin});
            minVal=min({minVal,grid[i][j]*leftMax,grid[i][j]*leftMin});
        }
        return dp[i][j]={maxVal,minVal};
    } 
public:
    int maxProductPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        dp.resize(m,vector<pair<long long,long long>>(n,{LLONG_MIN,LLONG_MIN}));
        const int MOD=1e9+7;
        // auto [maxVal,minVal]=helper(grid,0,0);
        // if(maxVal<0) return -1;
        // return maxVal%MOD;

        dp[0][0]={grid[0][0],grid[0][0]};
        for(int i=1;i<m;i++){
            dp[i][0]=make_pair(dp[i-1][0].first*grid[i][0],dp[i-1][0].second*grid[i][0]);
        }
        for(int j=1;j<n;j++){
            dp[0][j]=make_pair(dp[0][j-1].first*grid[0][j],dp[0][j-1].second*grid[0][j]);

        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j].first=max({dp[i-1][j].first*grid[i][j],dp[i-1][j].second*grid[i][j],
                dp[i][j-1].first*grid[i][j],dp[i][j-1].second*grid[i][j]});

                dp[i][j].second=min({dp[i-1][j].first*grid[i][j],dp[i-1][j].second*grid[i][j],
                dp[i][j-1].first*grid[i][j],dp[i][j-1].second*grid[i][j]});
            }
        }
        if(dp[m-1][n-1].first<0) return -1;
        return dp[m-1][n-1].first%MOD;
    }
};