// 3895. Count Digit Appearances
class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count=0;
        for(auto &num:nums){
            while(num>0){
                if(num%10==digit) count++;
                num/=10;
            }
        }
        return count;
    }
};