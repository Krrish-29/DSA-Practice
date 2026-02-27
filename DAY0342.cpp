// 3640. Trionic Array II
class Solution {
private:
    vector<vector<long long>>dp;
    long long solve(vector<int>&nums,int idx,int range){
        if(idx>=nums.size()) return range==3?0:LLONG_MIN/2;
        if(dp[idx][range]!=LLONG_MIN) return dp[idx][range];
        long long sum=LLONG_MIN/2;
        if(range==0){
            sum=max(sum,solve(nums,idx+1,0));
            if(idx+1<nums.size()&&nums[idx]<nums[idx+1]){
                sum=max(sum,nums[idx]+solve(nums,idx+1,1));
            }
        }
        else if(range==1&&idx+1<nums.size()){
            if(nums[idx]>nums[idx+1]){
                sum=max(sum,nums[idx]+solve(nums,idx+1,2));
            }
            else if(nums[idx]<nums[idx+1]){
                sum=max(sum,nums[idx]+solve(nums,idx+1,1));
            }
        }
        else if(range==2&&idx+1<nums.size()){
            if(nums[idx]<nums[idx+1]){
                sum=max(sum,nums[idx]+solve(nums,idx+1,3));
            }
            else if(nums[idx]>nums[idx+1]){
                sum=max(sum,nums[idx]+solve(nums,idx+1,2));
            }
        }
        else if(range==3){
            sum=max(sum,nums[idx]*1LL);
            if(idx+1<nums.size()&&nums[idx]<nums[idx+1]){
                sum=max(sum,nums[idx]+solve(nums,idx+1,3));
            }
        }
        return dp[idx][range]=sum;
    }
public:
    long long maxSumTrionic(vector<int>& nums) {
        dp.resize(nums.size(),vector<long long>(4,LLONG_MIN));
        return solve(nums,0,0);
    }
};