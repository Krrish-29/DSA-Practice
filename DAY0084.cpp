// 55. Jump Game
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size=nums.size();
        int capacity=0;
        for(int i=0;i<size;i++){
            if(capacity<i) return false;
            capacity=max(capacity,i+nums[i]);
        }
        return true;
    }
};