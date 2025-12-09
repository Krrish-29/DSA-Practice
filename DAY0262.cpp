// 3583. Count Special Triplets
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD=1e9+7;
        unordered_map<int,int>prefix,suffix;
        int count=0,size=nums.size();
        for(int num:nums) prefix[num]++;
        for(int i=0;i<size;i++){
            prefix[nums[i]]--;
            count=(count+(suffix[nums[i]*2]*1LL*prefix[nums[i]*2])%MOD)%MOD;
            suffix[nums[i]]++;
        }
        return count;
    }
}; 