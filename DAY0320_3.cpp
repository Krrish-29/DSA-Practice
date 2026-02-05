// 300. Longest Increasing Subsequence
class Solution {
private:
    vector<vector<int>>dp;
    int helper(vector<int>&nums,int idx,int prev){
        if(idx==nums.size()) return 0;
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        int len=0;
        if(prev==-1||nums[idx]>nums[prev]) len=max(1+helper(nums,idx+1,idx),helper(nums,idx+1,prev));
        else len=max(len,helper(nums,idx+1,prev));
        return dp[idx][prev+1]=len;

    }
public:
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size(),vector<int>(nums.size()+1,-1));
        return helper(nums,0,-1);

        // vector<int>tails;
        // for(int &num:nums){
        //     auto it=lower_bound(tails.begin(),tails.end(),num);
        //     if(it==tails.end()) tails.push_back(num);
        //     else *it=num;
        // }
        // return tails.size();
    }
};