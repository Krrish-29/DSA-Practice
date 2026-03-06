// 198. House Robber
class Solution {
private:
    vector<int>dp;
    int solve(vector<int> &nums,int idx){
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=INT_MIN) return dp[idx];
        return dp[idx]=max(solve(nums,idx+2)+nums[idx],solve(nums,idx+1));
    }
public:
    int rob(vector<int>& nums) {

        // recursive  
        // int size=nums.size();
        // dp.resize(size,INT_MIN);
        // return solve(nums,0);


        // iterative
        // dp[i] state tell that the max profit till house i
        // int size=nums.size();
        // dp.resize(size,INT_MIN);
        // if(size==1) return nums[0];
        // if(size==2) return max(nums[0],nums[1]);
        // dp[0]=nums[0];
        // dp[1]=max(nums[0],nums[1]);
        // for(int i=2;i<size;i++){
        //     dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        // }
        // return dp[size-1];


        // iterative with constant space
        int size=nums.size();
        if(size==1) return nums[0];
        if(size==2) return max(nums[0],nums[1]);
        int lastHouse=nums[0],secondLastHouse=max(nums[0],nums[1]);
        for(int i=2;i<size;i++){
            int current=max(lastHouse+nums[i],secondLastHouse);
            lastHouse=secondLastHouse;
            secondLastHouse=current;
        }
        return secondLastHouse;
    }
};