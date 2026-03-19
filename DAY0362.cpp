// 368. Largest Divisible Subset
class Solution {
private:
    vector<int>ans;
    void helper(vector<int>&nums,int idx,int prevIdx,vector<int>&curr){
        if(idx==nums.size()) {
            if(curr.size()>ans.size()) ans=curr;
            return ;
        }
        helper(nums,idx+1,prevIdx,curr);
        if(prevIdx==-1||(nums[prevIdx]%nums[idx]==0||nums[idx]%nums[prevIdx]==0)){
            curr.push_back(nums[idx]);
            helper(nums,idx+1,idx,curr);
            curr.pop_back();
        }
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // vector<int>curr;
        // helper(nums,0,-1,curr);
        // return ans;
        
        int size=nums.size(),maxL=1,lastIdx=0;
        vector<int>dp(size,1);
        vector<int>prev(size,-1);
        for(int i=1;i<size;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                    }
                    if(dp[i]>maxL){
                        maxL=dp[i];
                        lastIdx=i;
                    }
                }
            }
        }
        vector<int>ans;
        while(lastIdx!=-1){
            ans.push_back(nums[lastIdx]);
            lastIdx=prev[lastIdx];
        }   
        return ans;
    }
};