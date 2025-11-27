// 3381. Maximum Subarray Sum With Length Divisible by K
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        // Kadane's algo for a block of elements and useful observation is that after i=k subarrys repeat
        int size=nums.size();
        vector<long long>prefix(size);
        prefix[0]=nums[0];
        for(int i=1;i<size;i++) prefix[i]=prefix[i-1]+nums[i];
        if(size==k) return prefix[size-1];
        long long res=LLONG_MIN,maxEnd=0;
        for(int s=0;s<k;s++){
            int i=s;
            long long currSum=0;
            while(i+k-1<size){
                if(i==0) maxEnd=prefix[i+k-1];
                else maxEnd=prefix[i+k-1]-prefix[i-1];
                currSum=max(maxEnd,currSum+maxEnd);
                res=max(res,currSum);
                i+=k;
            }
        }
        return res;
    }
};