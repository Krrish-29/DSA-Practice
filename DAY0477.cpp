// 3987. Minimum Total Cost to Process All Elements
class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        int size=nums.size(),res=0;
        long long op=0;
        float diff;
        int times;
        const int MOD=1e9+7;
        for(int i=0;i<size;i++){
            if(nums[i]>res){
                diff=nums[i]-res;
                times=ceil((diff)/k);
                op=(op+times)%MOD;
                res+=k*times;
            }
            res-=nums[i];
        }
        return ((op*(op-1))/2)%MOD;
    }
};