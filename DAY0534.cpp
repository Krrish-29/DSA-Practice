// 115. Distinct Subsequences
class Solution {
private:
    // vector<vector<int>>dp;
    // int helper(string &s,string &t,int i,int j){
    //     if(j==t.size()) return 1;
    //     if(i==s.size()) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int count=0;
    //     if(s[i]==t[j]) count+=helper(s,t,i+1,j+1);
    //     count+=helper(s,t,i+1,j);
    //     return dp[i][j]=count;
    // }
public:
    int numDistinct(string s, string t) {
        // simple take skip dp solution having time and space of m*n
        // int size1=s.size(),size2=t.size();
        // dp.resize(size1,vector<int>(size2,-1));
        // return helper(s,t,0,0);
        
        // iterative dp with time and space m*n
        // dp[i][j] is distint subseq of s[0..i-1] that form t[0..j-1]
        // dp[i][0] since empty t can always be formed 
        // int size1=s.size(),size2=t.size();
        // vector<vector<int>>dp(size1+1,vector<int>(size2+1,0));
        // for(int i=0;i<=size1;i++) dp[i][0] = 1;
        // for(int i=1;i<=size1;i++){
        //     for(int j=1;j<=size2;j++){
        //         if(s[i-1]==t[j-1]){
        //             dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        //         }else{
        //             dp[i][j] = dp[i-1][j];
        //         }
        //     }
        // }
        // return dp[size1][size2];

        // since the row i depends on i-1 
        // simply remove i from the dp usage and we need to traverse j from size2 to 1 to not overwrite the 
        // j using j-1 and that change will be added to all values increasingly
        // time is m*n and space is n
        int size1=s.size(),size2=t.size();
        vector<int>dp(size2+1,0);
        dp[0] = 1;
        for(int i=1;i<=size1;i++){
            for(int j=size2;j>=1;j--){
                if(s[i-1]==t[j-1]){
                    dp[j] = dp[j-1] + dp[j];
                }else{
                    dp[j] = dp[j];
                }
            }
        }
        return dp[size2];
    }
};