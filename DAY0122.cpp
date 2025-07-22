// 1695. Maximum Erasure Value
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int size=nums.size();
        vector<int>hashmap(10001,0);
        int maxsum=0,i=0,currsum=0;
        for(int j=0;j<size;j++){
            if(hashmap[nums[j]]!=0){
                while(nums[i]!=nums[j]){
                    hashmap[nums[i]]--;
                    currsum-=nums[i];
                    i++;
                }
                hashmap[nums[i]]--;
                currsum-=nums[i];
                i++;
            }
            hashmap[nums[j]]++;
            currsum+=nums[j];
            maxsum=max(maxsum,currsum);
        }
        return maxsum;
    }
};