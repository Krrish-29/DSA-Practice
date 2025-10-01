// 322. Coin Change
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        vector<int>dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++) 
            for(int coin:coins) 
                if(coin<=i) dp[i]=min(1+dp[i-coin],dp[i]);
        return dp[amount]==amount+1?-1:dp[amount];
    }
};