// 4011. Count Subarrays With Even Odd Ratio I
class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        // simple brute force 
        int size = nums.size(),subarrays = 0;
        float ratio = float(a)/b ,even ,odd;
        for(int i = 0;i < size;i++){
            even = 0;
            odd = 0;
            for(int j = i;j < size;j++){
                if(nums[j]%2 == 0) even += 1;
                else odd += 1;
                if(even/odd <= ratio) subarrays++;
            }
        }
        return subarrays;
    }
};