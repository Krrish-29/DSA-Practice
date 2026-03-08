// 3862. Find the Smallest Balanced Index
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int size=nums.size();
        const int MOD=1e9+7;
        vector<long long>prefixSum(size,0);
        prefixSum[0]=nums[0];
        for(int i=1;i<size;i++){
            prefixSum[i]=(prefixSum[i-1]+nums[i])%MOD;
        }
        vector<long long>productSuffix(size,0);
        productSuffix[size-1]=nums[size-1];
        for(int i=size-2;i>=0;i--){
            productSuffix[i]=(productSuffix[i+1]*1LL*nums[i])%(MOD);
        }
        for(int i=0;i<size;i++){
            int sum=i-1>=0?prefixSum[i-1]:0;
            int product=i+1<size?productSuffix[i+1]:1;
            if(sum==product) return i;
        }
        return -1;
    }
};