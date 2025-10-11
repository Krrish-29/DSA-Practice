// 3708. Longest Fibonacci Subarray
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxlength=0,currlength=0,size=nums.size();
        for(int i=0;i<size-2;i++){
            if(nums[i]+nums[i+1]==nums[i+2]){
                currlength++;
            }
            else {
                maxlength=max(currlength+2,maxlength);
                currlength=0;
            }
        }
        return max(maxlength,currlength+2);
    }
};