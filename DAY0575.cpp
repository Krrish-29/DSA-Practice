// 3122. Minimum Number of Operations to Satisfy Conditions
class Solution {
private:
    int m,n;
    vector<vector<int>>dp;
    int helper(vector<vector<int>>& mat,int idx,int prev){
        if(idx == n) return 0;
        if(dp[idx][prev+1]!=INT_MAX) return dp[idx][prev+1];
        int minOp = INT_MAX;
        for(int i=0;i<10;i++){
            if(prev != i) minOp = min(minOp,mat[idx][i]+helper(mat,idx+1,i));
        }
        return dp[idx][prev+1] = minOp;
    }
public:
    int minimumOperations(vector<vector<int>>& grid) {
        // the idea is to compress this grid to just the numbers and their freq in each column , since we need to make each 
        // column elements same and also two adjacent columns should have different numbers 
        // compress using a 2 d vector which will store the freq of each column 
        // the freq will be counted for 0 to 9 and to make calculation easy , what we are counting is how many operations
        // it will take to convert the whole column into that number , which we can do by starting each freq with m
        // and subtaracting 1 when we see that number, at the end this tells us how many operations it would require to convert 
        // the whole column into each of the numbers, then first apply recursion starting with idx = 0 and previous number 
        // of the column as -1 then try to go over all 0 to 9 numbers which are different than what prev column number is 
        // add the operations and move to next state with idx+1 and prev as i , and for the base case when the idx == n return 0 simply
        // for memoization the state depends on idx and prev and also since the prev can be -1 use prev+1 in dp 
        // and initialize the dp with n and vector<int>(11,-1)

        // preprocess
        // this is to count how many operations will it take to convert this whole column to a particluar value
        m = grid.size();
        n = grid[0].size();
        int value;
        vector<vector<int>>mat(n,vector<int>(10,m));
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                value = grid[i][j];
                mat[j][value]--;
            }
        }
        dp.resize(n,vector<int>(11,INT_MAX));
        // return helper(mat,0,-1);

        // iterative
        for(int i=0;i<10;i++){
            dp[0][i]=mat[0][i]; // initialize the first columns values
        }
        for(int i=1;i<n;i++){
            // for each value of the curr column check against the other values that prev column can take
            for(int curr=0;curr<10;curr++){
                for(int prev=0;prev<10;prev++){
                    if(curr != prev) dp[i][curr] = min(dp[i][curr],mat[i][curr]+dp[i-1][prev]);
                }
            }
        }
        int minOp=INT_MAX;
        for(int i=0;i<10;i++){ // find the minimum operations from the last column values 
            minOp = min(minOp,dp[n-1][i]);
        }
        return minOp;
    }
};