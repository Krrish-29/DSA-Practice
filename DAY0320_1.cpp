// 3201. Find the Maximum Length of Valid Subsequence I
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even=0,odd=0,prev=nums[0],alt=1;
        for(int num:nums){
            if(num%2==0) even++;
            else odd++;
            if(prev%2!=num%2){
                prev=num;
                alt++;
            }
        }
        return max({even,odd,alt});
    }
};