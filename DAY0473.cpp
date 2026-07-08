// 3974. Maximum Total Sum of K Selected Elements
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long sum=0;
        sort(nums.begin(),nums.end());
        int size=nums.size();
        for(int i=size-1;i>=size-k;i--){
            if(mul==0) {
                sum+=nums[i];
            }
            else{
                sum+=(mul*1LL*nums[i]);
                mul--;
            }
        }
        return sum;
    }
};