// 4088. Difference Between Peaks and Valleys
class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int diff=0;
        for(int i=1;i<nums.size()-1;i++){
            if( nums[i] > nums[i+1] && nums[i] > nums[i-1]) diff += nums[i];
            if( nums[i] < nums[i+1] && nums[i] < nums[i-1]) diff -= nums[i];
        }
        return diff;
    }
};