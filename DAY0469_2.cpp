// 3979. Maximum Valid Pair Sum
class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        vector<int>prefixMax(nums.size(),0);
        int size=nums.size(),maxSum=0;
        prefixMax[size-1]=nums[size-1];
        for(int i=size-2;i>=0;i--){
            prefixMax[i]=max(prefixMax[i+1],nums[i]);
        }
        for(int i=0;i<size-k;i++){
            maxSum=max(maxSum,nums[i]+prefixMax[i+k]);
        }
        return maxSum;
    }
};