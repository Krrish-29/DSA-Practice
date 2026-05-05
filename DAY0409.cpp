// 287. Find the Duplicate Number
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // consider the elems as idx to which they connect since the values are in 1 to n
        // we can safely assume so and thinking of this as a graph of some sort
        // and checking cycles on it using slow and fast pointer we can find duplicates (cycles in the graph)
        int size=nums.size();
        int slow=nums[0],fast=nums[0];
        while(1){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast) break;
        }
        int ans=nums[0];
        while(slow!=ans){
            slow=nums[slow];
            ans=nums[ans];
        }
        return ans;
    }
};