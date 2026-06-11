// 2302. Count Subarrays With Score Less Than K
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long left=0,size=nums.size(),sum=0,len,count=0;
        for(int right=0;right<size;right++){
            sum+=nums[right];
            len=right-left+1;
            while(sum*len>=k){
                sum-=nums[left];
                left++;
                len=right-left+1;
            }
            count+=len;
        }
        return count;
    }
};