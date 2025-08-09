// 3627. Maximum Median Sum of Subsequences of Size 3
class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        long long median=0;
        int size=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=size-1;
        while(i<j){
            j--;
            median+=nums[j--];
            i++;
        }
        return median;
    }
};