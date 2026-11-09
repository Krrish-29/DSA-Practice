// 4089. Count Subarrays With Loose Bounds
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // if 1 number obey the rule we have 1 valid subarray
        // if 2 consecutive then we will have 2 (1 that number + 1 both numbers)
        // if 3 consecutive then we will have 3 (1 that number + 1 all three numbers + 1 current and prev number)
        // anytime we see a number which does not obey the limits the streak will get lost
        // as any subarray containing that number will not be valid therefore we need to start a new
        // sequence after the number
        long long consecutive = 0, count = 0;
        for(int &num:nums){
            if( minK > num || maxK < num) consecutive = 0; 
            else consecutive++;
            count += consecutive;
        }
        return count;
    }
};