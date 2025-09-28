// 128. Longest Consecutive Sequence
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>hash;
        int maxCount=0,size=nums.size();
        for(int num:nums){
            hash.insert(num);
        }
        int start,end;
        for(int i=0;i<size;i++){
            start=nums[i];
            end=nums[i];
            hash.erase(start);
            while(hash.find(start-1)!=hash.end()) {
                hash.erase(start);
                start--;
            }
            while(hash.find(end+1)!=hash.end()) {
                hash.erase(end);
                end++;
            }
            maxCount=max(maxCount,end-start+1);
        }
        return maxCount;
    }
};