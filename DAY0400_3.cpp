// 3914. Minimum Operations to Make Array Non Decreasing
class Solution {
public:
    long long minOperations(vector<int>& nums) {
        // just count the drops
        int size=nums.size();
        long long x=0;
        int diff=0;
        for(int i=1;i<size;i++){
            diff=0;
            if(nums[i-1]>nums[i]){
                diff=nums[i-1]-nums[i];
                x+=diff;
            }
        }
        return x;
    }
};