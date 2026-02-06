// 3830. Longest Alternating Subarray After Removing At Most One Element
class Solution {
private:
    vector<vector<vector<int>>>dp;
    int helper(vector<int>&nums,int &size,int idx,bool inc,bool skip){
        if(size<=idx+1) return 0;
        if(dp[idx][inc][skip]!=-1) return dp[idx][inc][skip];
        int len=0;
        if(inc&&nums[idx+1]>nums[idx]) len=max(len,1+helper(nums,size,idx+1,false,skip));
        else if(!inc&&nums[idx+1]<nums[idx]) len=max(len,1+helper(nums,size,idx+1,true,skip));
        if(!skip&&idx+2<size){
            if(inc&&nums[idx+2]>nums[idx]) len=max(len,1+helper(nums,size,idx+2,false,true));
            else if(!inc&&nums[idx+2]<nums[idx]) len=max(len,1+helper(nums,size,idx+2,true,true));
        }
        return dp[idx][inc][skip]=len;
    }
public:
    int longestAlternating(vector<int>& nums) {
        int size=nums.size();
        dp.resize(size,vector<vector<int>>(2,vector<int>(2,-1)));
        int len=1;
        for(int i=0;i<size;i++) len=max({len,1+helper(nums,size,i,true,false),1+helper(nums,size,i,false,false)});
        return len;
    }
};