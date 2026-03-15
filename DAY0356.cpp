// 646. Maximum Length of Pair Chain
class Solution {
private:
    vector<int>dp;
    int helper(vector<vector<int>>& pairs,int idx){
        if(idx==pairs.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int len=1;
        for(int j=0;j<idx;j++){
            if(pairs[j][1]<pairs[idx][0])
            len=max(len,1+helper(pairs,j));
        }
        return dp[idx]=len;
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        dp.resize(pairs.size(),-1);
        int len=1;
        for(int i=0;i<pairs.size();i++){
            len=max(len,helper(pairs,i));
        }
        return len;
    }
};