// 300. Longest Increasing Subsequence
// tried again for better understanding of dp
class Solution {
// private:
//     vector<vector<int>>dp;
//     int helper(vector<int>&nums,int idx,int prev){
//         if(idx==nums.size()) return 0;
//         if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
//         int len=0;
//         if(prev==-1||nums[idx]>nums[prev]) len=max(1+helper(nums,idx+1,idx),helper(nums,idx+1,prev));
//         else len=max(len,helper(nums,idx+1,prev));
//         return dp[idx][prev+1]=len;
//     }
public:
    int lengthOfLIS(vector<int>& nums) {
        // recursive n^2
        // dp.resize(nums.size(),vector<int>(nums.size()+1,-1));
        // return helper(nums,0,-1);
        
        // bottoms up n^2
        // state is dp[i] is the longest chain at index i
        int maxLen=1,size=nums.size();
        vector<int>dp(size,1);
        for(int i=1;i<size;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]) dp[i]=max(dp[i],dp[j]+1);
            }
            maxLen=max(maxLen,dp[i]);
        }
        return maxLen;

        // greedy n
        // vector<int>tails;
        // for(int &num:nums){
        //     auto it=lower_bound(tails.begin(),tails.end(),num);
        //     if(it==tails.end()) tails.push_back(num);
        //     else *it=num;
        // }
        // return tails.size();
    }
};