// 1877. Minimize Maximum Pair Sum in Array
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int left=0,right=nums.size()-1,maxMin=INT_MIN;
        while(left<right){
            maxMin=max(maxMin,nums[left]+nums[right]);
            left++;
            right--;
        }
        return maxMin;
    }
};