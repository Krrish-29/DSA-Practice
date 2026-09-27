// 4058. Maximum Pulse Value After One Subarray Rotation
class Solution {
public:
    long long maxValue(vector<int>& nums) {
        // observation is that for some range if flipped can increase or decrease the total pulse value ,
        // if the subarray with sum > 0 is flipped then its contribution will be total-2*sum
        // therefore we need to find the subarray with sum < 0 so that is can increase the total 
        // now coming to subarrays if the subarray is odd and flipped then we can see that the sign of first elem after its at the back
        // remains same therefore it contributes(changes) nothing , making a odd subarray just a even subarray 
        // so we need to find the even subarry with min sum possible
        // for min sum possible we can simply follow kaden's algo
        // for even subarray we start with min sum of odd and even array as MAX
        // at any idx i even subarray + nums[i] will result in a new odd subarray 
        // and ood subarray + nums[i] will result in new even subarray but since we need to minimize using kaden's
        // we have a option to start new odd subarray with nums[i]
        int size=nums.size();
        long long sum=0,res=INT_MAX,maxEnd=INT_MAX;
        long long odd,even,prevodd=INT_MAX,preveven=0;
        for(int i=0;i<size;i++){
            if(i%2==1) nums[i] = - nums[i];
            sum+=nums[i];
            odd = min(1LL*nums[i],preveven+nums[i]);
            even = prevodd + nums[i];
            res = min(res,even);

            prevodd = odd;
            preveven = even;
        }
        return max(sum,sum-2*(res));
    }
};