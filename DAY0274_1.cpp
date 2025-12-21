// 1143. Longest Common Subsequence
class Solution {
private:
    int m,n;
    vector<vector<int>>dp;
    int lcs(string &text1,int i,string &text2,int j){
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]) return dp[i][j]=1+lcs(text1,i-1,text2,j-1);
        else return dp[i][j]=max(lcs(text1,i-1,text2,j),lcs(text1,i,text2,j-1));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        m=text1.size(),n=text2.size();
        dp.resize(m,vector<int>(n,-1));
        lcs(text1,m-1,text2,n-1);
        return dp[m-1][n-1];

        // vector<vector<int>>table(m+1,vector<int>(n+1,0));
        // for(int i=1;i<=m;i++){
        //     for(int j=1;j<=n;j++){
        //         if(text1[i-1]==text2[j-1]) table[i][j]=1+table[i-1][j-1];
        //         else table[i][j]=max(table[i][j-1],table[i-1][j]);
        //     }
        // }
        // return table[m][n];
    }
};