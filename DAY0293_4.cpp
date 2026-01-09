// 645. Set Mismatch
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int size=nums.size();
        vector<int>map(size,0);
        for(int i=0;i<size;i++){
            map[nums[i]-1]+=1;
        }
        int missing,extra;
        for(int i=0;i<size;i++){
            if(map[i]==2) extra=i+1;
            if(map[i]==0) missing=i+1;
        }
        return {extra,missing};
    }
};