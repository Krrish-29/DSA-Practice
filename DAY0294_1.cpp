// 712. Minimum ASCII Delete Sum for Two Strings
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int size1=s1.size(),size2=s2.size();
        vector<vector<int>>dp(size1+1,vector<int>(size2+1,0));
        for(int i=1;i<=size1;i++){
            for(int j=1;j<=size2;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=s1[i-1]+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int sum=0;
        for(char ch:s1) sum+=ch;
        for(char ch:s2) sum+=ch;
        return sum-2*dp[size1][size2];
    }
};