// 3392. Count Subarrays of Length Three With a Condition
class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int i=2;
            while(i<nums.size()){
                if((nums[i-2]+nums[i])*2.0==nums[i-1]) nums[i-2]=1;
                else nums[i-2]=0;
                if(i>=3) nums[i-2]+=nums[i-3];
                i++;
            }
            return nums[i-3]; 
        }
    };