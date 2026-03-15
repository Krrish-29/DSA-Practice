// 3867. Sum of GCD of Formed Pairs
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int size=nums.size();
        vector<int>prefixGcd(size,0);
        prefixGcd[0]=nums[0];
        for(int i=1;i<size;i++){
            prefixGcd[i]=max(prefixGcd[i-1],nums[i]);
        }
        for(int i=0;i<size;i++){
            prefixGcd[i]=gcd(prefixGcd[i],nums[i]);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        size=prefixGcd.size();
        long long gcdVal=0;
        for(int i=0;i<size/2;i++){
            gcdVal+=gcd(prefixGcd[i],prefixGcd[size-1-i]);
        }
        return gcdVal;
    }
};