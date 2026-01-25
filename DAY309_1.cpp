// 3818. Minimum Prefix Removal to Make Array Strictly Increasing
class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int x=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]) x=i;
        }
        return x;
    }
};