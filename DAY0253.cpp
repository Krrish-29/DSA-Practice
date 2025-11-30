// 1590. Make Sum Divisible by P
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int,int>map;
        int size=nums.size(),minLen=INT_MAX;
        for(int i=1;i<size;i++){
            nums[i]=(nums[i]+nums[i-1])%p;
        }
        int target=nums[size-1]%p;
        if(target==0) return 0;
        map[0]=-1;
        for(int i=0;i<size;i++){
            if(map.find((nums[i]-target+p)%p)!=map.end()){
                minLen=min(minLen,i-map[(nums[i]-target+p)%p]);
            }
            map[nums[i]%p]=i;
        }
        return minLen==size?-1:minLen;
    }
};