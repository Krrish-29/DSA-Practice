// 3512. Minimum Operations to Make Array Sum Divisible by K
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for(int i=1;i<nums.size();i++) nums[0]+=nums[i];
        return nums[0]%k;
    }
};