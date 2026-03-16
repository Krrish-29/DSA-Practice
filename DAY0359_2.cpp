// 646. Maximum Length of Pair Chain
// tried again for beter understanding
class Solution {
private:
    vector<vector<int>>dp;
    int helper(vector<vector<int>>&pairs,int idx,int prev){
        if(idx==pairs.size()) return 0;
        if(prev!=-1&&dp[idx][prev]!=-1) return dp[idx][prev];
        int skip=0,take=0;
        skip=helper(pairs,idx+1,prev);
        if(prev==-1||(prev!=-1&&pairs[prev][1]<pairs[idx][0])) take=1+helper(pairs,idx+1,idx);
        if(prev==-1) return max(skip,take);
        return dp[idx][prev]=max(skip,take);
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // recursive n^2
        sort(pairs.begin(),pairs.end());// since there is no condition we can select pairs in any order
        int size=pairs.size();
        dp.resize(size,vector<int>(size,-1));
        return helper(pairs,0,-1);

        // bottoms up n^2
        // state is dp[i] is the max len of pairs u can get at index i
        // sort(pairs.begin(),pairs.end());
        // int size=pairs.size(),maxLen=1;
        // vector<int>dp(size,1);
        // for(int i=1;i<size;i++){
        //     for(int j=0;j<i;j++){
        //         if(pairs[j][1]<pairs[i][0]) dp[i]=max(dp[i],dp[j]+1);
        //     }
        //     maxLen=max(maxLen,dp[i]);
        // }
        // return maxLen;
    }
};