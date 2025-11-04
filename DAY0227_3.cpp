// 3727. Maximum Alternating Sum of Squares
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sum=0;
        int size=nums.size();
        for(int i=0;i<size;i++) nums[i]=abs(nums[i]);
        sort(nums.begin(),nums.end());
        for(int i=0;i<size;i++){
            if(i<size/2) sum-=(nums[i]*nums[i]);
            else sum+=(nums[i]*nums[i]);
        }
        return sum;
    }
};