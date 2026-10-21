// 4074. Maximum Product Pair With Target Sum
class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        // simple brute force 
        int size=nums.size();
        vector<int>ans={-1,-1}; // indices 
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(nums[i]>nums[j] && (nums[i]+nums[j])==target){
                    if(ans[0] == -1 || nums[i]*nums[j] > nums[ans[0]]*nums[ans[1]]){
                        ans[0]=i;
                        ans[1]=j;
                    }
                }
            }
        }
        return ans;
    }
};