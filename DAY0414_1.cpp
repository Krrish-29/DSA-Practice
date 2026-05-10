// 3925. Concatenate Array With Reverse
class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int>ans;
        int size=nums.size();
        for(int i=0;i<size;i++) ans.push_back(nums[i]);
        for(int i=size-1;i>=0;i--) ans.push_back(nums[i]);
        return ans;
    }
};