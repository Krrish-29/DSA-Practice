// 260. Single Number III
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long XOR=0;
        int size=nums.size();
        for(int i=0;i<size;i++){
            XOR^=nums[i];
        }
        XOR =XOR  & -XOR;
        int num1=0,num2=0;
        for(int i=0;i<size;i++){
            if(nums[i]&XOR){
                num1^=nums[i];
            }
            else{
                num2^=nums[i];
            }
        }
        return {num2,num1};
    }
};