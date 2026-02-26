// 213. House Robber II
class Solution {
private:
    vector<int>dp;
    int solve(vector<int>&nums,int idx,int limit){
        if(idx>limit) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take=nums[idx]+solve(nums,idx+2,limit);
        int skip=solve(nums,idx+1,limit);
        return dp[idx]=max(take,skip);
    }
public:
    int rob(vector<int>& nums) {
        // recursion + memo starting from 0 to n-2 and 1 to n-1
        // int size=nums.size();
        // if(size==1) return nums[0];
        // if(size==2) return max(nums[0],nums[1]);
        // dp.resize(size,-1);
        // int takeHouse1=solve(nums,0,size-2);
        // dp.clear();
        // dp.resize(size,-1);
        // // nums[0]=0; //will work since we are making contribution of house 1 to 0
        // // int donotTakeHouse1=solve(nums,0,size-1);
        // int donotTakeHouse1=solve(nums,1,size-1);
        // return max(takeHouse1,donotTakeHouse1);


        // bottom up starting from 0 to n-2 and 1 to n-1
        // int size=nums.size();
        // if(size==1) return nums[0];
        // if(size==2) return max(nums[0],nums[1]);
        // dp.resize(size+1,0);
        // dp[0]=0;
        // dp[1]=nums[0];
        // dp[2]=max(nums[0],nums[1]);
        // for(int i=2;i<=size-1;i++){
        //     dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
        // }
        // int takeHouse1=dp[size-1];
        // dp.clear();
        // dp.resize(size+1,0);
        // // nums[0]=0;
        // dp[0]=0;
        // // dp[1]=nums[0];
        // dp[1]=0;
        // dp[2]=nums[1];
        // for(int i=2;i<=size;i++){
        //     dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
        // }
        // int donotTakeHouse1=dp[size];
        // return max(takeHouse1,donotTakeHouse1);

        //  constant space
        int size=nums.size();
        if(size==1) return nums[0];
        if(size==2) return max(nums[0],nums[1]);
        int lastHouse=nums[0],secLastHouse=0,currHouse=0;
        for(int i=2;i<=size-1;i++){
            currHouse=max(nums[i-1]+secLastHouse,lastHouse);
            secLastHouse=lastHouse;
            lastHouse=currHouse;
        }
        int takeHouse1=lastHouse;

        nums[0]=0;
        lastHouse=nums[0],secLastHouse=0,currHouse=0;
        for(int i=2;i<=size;i++){
            currHouse=max(nums[i-1]+secLastHouse,lastHouse);
            secLastHouse=lastHouse;
            lastHouse=currHouse;
        }
        int donotTakeHouse1=lastHouse;
        return max(takeHouse1,donotTakeHouse1);
    }
};