// 4083. Minimum Deletions to Make Array Sharp
class Solution {
public:
    int minDeletions(vector<int>& nums) {
        // remove consecutive same numbers
        int deletions = 0,curr = -1,size = nums.size();
        for(int i = 0; i < size; i++){
            if(curr == nums[i]) deletions++;
            else curr = nums[i];
        }
        return deletions;
    }
};