// 485. Max Consecutive Ones
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0,temp=0;
        for(int num:nums){
            if(num==1) temp++;
            else temp=0;
            count=max(count,temp);
        }
        return count;
    }
};