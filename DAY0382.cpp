// 3891. Minimum Increase to Maximize Special Indices
class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        long long ans1=0,ans2=0;
        int size=nums.size();
        vector<long long>odd(size,INT_MAX),even(size,INT_MAX);
        for(int i=1;i<size-1;i+=2){
            if(max(nums[i-1],nums[i+1])+1>nums[i]){
                ans1+=max(nums[i-1],nums[i+1])+1-nums[i];
            }
            odd[i]=ans1;
        }
        for(int i=size-2;i>0;i-=2){
            if(max(nums[i-1],nums[i+1])+1>nums[i]){
                ans2+=max(nums[i-1],nums[i+1])+1-nums[i];
            }
            even[i]=ans2;
        }
        if(size%2==1) return ans1;
        long long ans=min(ans1,ans2);
        for(int i=2;i<size-2;i+=2){
            ans=min(ans,odd[i-1]+even[i+2]);
        }
        return ans;
    }
};