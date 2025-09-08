// 209. Minimum Size Subarray Sum
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size=nums.size(),sum=0,minLen=INT_MAX;
        for(int i=0,j=0;i<size&&j<size;j++){
            sum+=nums[j];
            while(i<size&&sum>=target){
                minLen=min(minLen,j-i+1);
                sum-=nums[i];
                i++;
            }    
        }
        return minLen==INT_MAX?0:minLen;
    }
};