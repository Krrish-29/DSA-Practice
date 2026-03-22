// 3877. Minimum Removals to Achieve Target XOR
class Solution {
private:
    vector<vector<int>>dp;
    int helper(vector<int>& nums, int target,int idx,int prevXor){
        if(idx>=nums.size()) {
            if(target==prevXor) return 0;
            return -1e9;
        }
        if(dp[idx][prevXor]!=-1) return dp[idx][prevXor];
        int take=1+helper(nums,target,idx+1,nums[idx]^prevXor);
        int notTake=helper(nums,target,idx+1,prevXor);
        return dp[idx][prevXor]=max(take,notTake);
    }
public:
    int minRemovals(vector<int>& nums, int target) {
        // since the max limit is 1e4 which is less than 1<<14 or 2^14 use that as upperlimit for xor
        dp.resize(nums.size(),vector<int>(1<<14,-1));
        int ans=helper(nums,target,0,0);
        if(ans<0) return -1;
        return nums.size()-ans;
        // unordered_map<int,int>map;
        // map[0]=0;
        // for(int &num:nums){
        //     unordered_map<int,int>newMap=map;
        //     for(auto &[x,count]:map){
        //         int newX=num^x;
        //         if(newMap.find(newX)==newMap.end()) newMap[newX]=count+1;
        //         else newMap[newX]=max(newMap[newX],count+1);
        //     }
        //     map=newMap;
        // }
        // return map.find(target)==map.end()?-1:nums.size()-map[target];
    }
};