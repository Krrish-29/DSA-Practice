// 3202. Find the Maximum Length of Valid Subsequence II
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int size=nums.size(),res=2;
        for(int j=0;j<k;j++){
            vector<int>dp(k,0);
            for(int i=0;i<size;i++){
                int rem=nums[i]%k;
                dp[rem]=dp[(j+k-rem)%k]+1;
            }
            for(int val:dp) res=max(val,res);
        }
        return res;
    }
};