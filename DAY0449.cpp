// 3689. Maximum Total Subarray Value I
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxVal=*max_element(nums.begin(),nums.end());
        int minVal=*min_element(nums.begin(),nums.end());
        return (maxVal-minVal)*1LL*k;
    }
};