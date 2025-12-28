// 3788. Maximum Score of a Split
class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int size=nums.size();
        vector<long long>suffix(size,0);
        vector<long long>prefix(size+1,0);
        suffix[size-1]=nums[size-1];
        for(int i=size-2;i>=0;i--){
            suffix[i]=min(1LL*nums[i+1],suffix[i+1]);
        }
        long long ans=LLONG_MIN;
        prefix[0]=nums[0];
        for(int i=1;i<size;i++){
            prefix[i]=prefix[i-1]+nums[i];
            ans=max(prefix[i-1]-suffix[i-1],ans);
        }
        return ans;
    }
};