// 3158. Find the XOR of Numbers Which Appear Twice
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<int>answer(51,0);
        int result=0;
        int size=nums.size();
        for(int i=0;i<size;i++){
            answer[nums[i]]++;
            if(answer[nums[i]]>1){
                result^=nums[i];
            }
        }
        return result;
    }
};