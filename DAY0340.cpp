// 70. Climbing Stairs
class Solution {
private:
    vector<int>dp;
    int climb(int n,int step){
        if(step==n) return 1;
        if(dp[step]!=-1) return dp[step];
        int ways=0;
        if(step+2<=n){
            ways+=climb(n,step+2);
        }
        ways+=climb(n,step+1);
        return dp[step]=ways;
    }
public:
    int climbStairs(int n) {
        dp.resize(n+1,-1);
        return climb(n,0);
        if(n<=3) return n;
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};