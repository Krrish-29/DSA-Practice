// 72. Edit Distance
// similar to lcs
class Solution {
private:
    vector<vector<int>>dp;
    int helper(string &word1,string &word2,int i,int j){
        if(i==0) return j;
        if(j==0) return i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i-1]==word2[j-1]) {
            return dp[i][j] = helper(word1,word2,i-1,j-1);
        }
        return dp[i][j] = 1+min({helper(word1,word2,i-1,j-1),
                    helper(word1,word2,i,j-1),
                    helper(word1,word2,i-1,j)});
    }
public:
    int minDistance(string word1, string word2) {
        // dp.resize(word1.size()+1,vector<int>(word2.size()+1,-1));
        // return helper(word1,word2,word1.size(),word2.size()); 


        // int m=word1.size(),n=word2.size();
        // for(int i=0;i<=m;i++){
        //     dp[i][0]=i;
        // }  
        // for(int j=0;j<=n;j++){
        //     dp[0][j]=j;
        // }
        // for(int i=1;i<=m;i++){
        //     for(int j=1;j<=n;j++){
        //         if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
        //         else dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
        //     }
        // }
        // return dp[m][n];

        int m=word1.size(),n=word2.size();
        vector<int>prev(n+1,0),curr(n+1,0);
        for(int j=0;j<=n;j++){
            prev[j]=j;
        }  
        for(int i=1;i<=m;i++){
            curr[0]=i;
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]) curr[j]=prev[j-1];
                else curr[j]=1+min({curr[j-1],prev[j],prev[j-1]});
            }
            prev=curr;
        }
        return prev[n];
    }
};