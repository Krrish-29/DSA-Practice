// 3862. Find the Smallest Balanced Index
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int size=nums.size();
        const int MOD=INT_MAX;
        vector<long long>prefixSum(size+1,0);
        prefixSum[0]=0;
        for(int i=1;i<=size;i++){
            prefixSum[i]=(prefixSum[i-1]+nums[i-1])%MOD;
        }
        vector<long long>productSuffix(size+1,1);
        productSuffix[size]=1;
        for(int i=size-2;i>=0;i--){
            productSuffix[i]=(productSuffix[i+1]*1LL*nums[i+1])%MOD;
        }
        for(int i=0;i<size;i++){
            if(prefixSum[i]==productSuffix[i]) return i;
        }
        return -1;
    }
};