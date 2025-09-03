// 16. 3Sum Closest
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size=nums.size(),left,right,close=nums[0]+nums[1]+nums[2],currSum;
        sort(nums.begin(),nums.end());
        for(int i=0;i<size-2;i++){
            left=i+1;
            right=size-1;
            while(left<right){
                currSum=nums[i]+nums[left]+nums[right];
                if(abs(currSum-target)<abs(close-target)) close=currSum;
                if(currSum>target) right--;
                else left++;
            }
        }
        return close;
    }
};