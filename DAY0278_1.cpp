// 3774. Absolute Difference Between Maximum and Minimum K Elements
class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0,size=nums.size();
        for(int i=0;i<k;i++) ans+=nums[i];
        for(int i=size-1;i>=size-k;i--) ans-=nums[i];
        return ans>0?ans:-1*ans;
    }
};