// 2210. Count Hills and Valleys in an Array
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int hillValley=0,size=nums.size(),dup=1;
        for(int i=1;i<size;i++){
            if(nums[i]!=nums[i-1]) nums[dup++]=nums[i]; 
        }
        for(int i=1;i<dup-1;i++){
            if((nums[i-1]>nums[i]&&nums[i]<nums[i+1])||(nums[i-1]<nums[i]&&nums[i]>nums[i+1])) hillValley++;
        }
        return hillValley;
    }
};