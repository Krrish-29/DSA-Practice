// 4097. Minimum Value of Merged Integers
class Solution {
private:
    int getDecimal(int num){
        int ten = 1;
        while(num > 0){
            num /= 10;
            ten *= 10;
        }
        return ten;
    }
public:
    int minMergedInteger(vector<int>& nums) {
        // just find the decimal places in nums[i+1] and multiply the nums[i] by 10^(decimals in nums[i+1])
        // and add nums[i+1] to get the actual number 
        int size = nums.size(),num2Length,minValue=INT_MAX;
        for(int i = 0; i < size; i+=2){
            minValue = min(minValue,  nums[i]*(getDecimal(nums[i+1])) + nums[i+1] );
        }
        return minValue;
    }
};