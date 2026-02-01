// 3828. Final Element After Subarray Deletions
class Solution {
public:
    int finalElement(vector<int>& nums) {
        int size=nums.size();
        return max(nums[0],nums[size-1]);
    }
};