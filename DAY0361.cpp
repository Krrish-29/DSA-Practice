// 1420. Build Array Where You Can Find The Maximum Exactly K Comparisons
class Solution {
private:
    int len,range,cost;
    const int MOD=1e9+7;
    vector<vector<vector<int>>>dp;
    int solve(int currLen,int maxSeen,int currCost){
        if(currLen==len){
            if(currCost==cost) return 1;
            return 0;
        } 
        if(dp[currLen][maxSeen][currCost]!=-1) return dp[currLen][maxSeen][currCost];
        long long arrays=0;
        for(int i=1;i<=range;i++){
            if(i>maxSeen) arrays=arrays+solve(currLen+1,i,currCost+1)%MOD;
            else arrays=arrays+solve(currLen+1,maxSeen,currCost)%MOD;
        }
        return dp[currLen][maxSeen][currCost]=arrays%MOD;
    }
public:
    int numOfArrays(int n, int m, int k) {
        len=n;
        range=m;
        cost=k;
        dp.resize(n+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(0,0,0);
    }
};