// 2221. Find Triangular Sum of an Array
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int size=nums.size();
        for(int i=size;i>=1;i--){
            for(int j=0;j<i-1;j++){
                nums[j]=(nums[j]+nums[j+1])%10;
            }
        }
        return nums[0];
    }
};