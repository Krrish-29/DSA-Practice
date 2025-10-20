// 334. Increasing Triplet Subsequence
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int size=nums.size();
        int one=INT_MAX,two=INT_MAX;
        for(int i=0;i<size;i++){
            if(nums[i]<=one) one=nums[i];
            else if(nums[i]<=two) two=nums[i];
            else return true;
        }
        return false;
    }
};