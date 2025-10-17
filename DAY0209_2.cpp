// 198. House Robber
class Solution {
private:
    // vector<int>memo;
    // int robbing(int current,vector<int>&nums){
    //     if(current>=nums.size()) return 0;
    //     if(memo[current]!=INT_MIN) return memo[current];
    //     return memo[current]=max(robbing(current+2,nums)+nums[current],robbing(current+1,nums));
    // }
public:
    int rob(vector<int>& nums) {
        // Iterative 
        // O(1) space
        int size=nums.size();
        if(size==1) return nums[0];
        if(size==2) return max(nums[0],nums[1]);
        int n2=nums[size-1],n1=max(nums[size-1],nums[size-2]),maxMoney;
        for(int i=size-3;i>=0;i--){
            maxMoney=max(nums[i]+n2,n1);
            n2=n1;
            n1=maxMoney;
        }
        return maxMoney;

        // O(n) space
        // int size=nums.size();
        // if(size==1) return nums[0];
        // if(size==2) return max(nums[0],nums[1]);
        // vector<int>dp(size,0);
        // dp[size-1]=nums[size-1];
        // dp[size-2]=max(nums[size-1],nums[size-2]);
        // for(int i=size-3;i>=0;i--){
        //     dp[i]=max(dp[i+2]+nums[i],dp[i+1]);
        // }
        // return dp[0];

        // Recursive 
        // int size=nums.size();
        // memo.resize(size,INT_MIN);
        // return robbing(0,nums);
    }
};