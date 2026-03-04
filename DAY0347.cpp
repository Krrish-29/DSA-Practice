// 1911. Maximum Alternating Subsequence Sum
class Solution {
private:
    vector<vector<long long>>dp;
    // long long solve(vector<int>&nums,int idx,bool subIdx){
    //     if(idx==nums.size()) return 0;
    //     if(dp[idx][subIdx]!=LLONG_MIN) return dp[idx][subIdx];
    //     long long skip=solve(nums,idx+1,subIdx);
    //     long long take=(subIdx%2==0)?nums[idx]:-nums[idx];
    //     take+=solve(nums,idx+1,(subIdx+1)%2);
    //     return dp[idx][subIdx]=max(skip,take);
    // }
public:
    long long maxAlternatingSum(vector<int>& nums) {
        dp.resize(nums.size(),vector<long long>(2,LLONG_MIN));
        // return solve(nums,0,0);


        // bottoms up 
        // state dp[i][0] tells that the subseq ending at i with even len 
        // state dp[i][1] tells that the subseq ending at i with odd len
        // we will have to add nums[i] if we want parity 1 and had it prev 0 ,and oppo 
        dp[0][0]=0;
        dp[0][1]=nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i][0]=max(dp[i-1][1]-nums[i],dp[i-1][0]);
            dp[i][1]=max(dp[i-1][0]+nums[i],dp[i-1][1]);
        }
        return max(dp[nums.size()-1][0],dp[nums.size()-1][1]);

    }
};