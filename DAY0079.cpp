// 136. Single Number
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer=nums[0];
        int size=nums.size();
        for(int i=1;i<size;i++){
            answer^=nums[i];
        }
        return answer;
    }
};