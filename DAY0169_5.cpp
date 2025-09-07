// 3674. Minimum Operations to Equalize Array
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int and_sum=nums[0];
        for(int num:nums) and_sum&=num;
        for(int num:nums){
            if(and_sum!=num) return 1;
        }
        return 0;
    }
};