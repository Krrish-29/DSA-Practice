// 3712. Sum of Elements With Frequency Divisible by K
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int currFreq=0,ans=0,prev=0;
        for(int num:nums){
            if(num==prev) currFreq++;
            else {
                if((currFreq+1)%k==0) ans+=(currFreq+1)*prev;
                prev=num;
                currFreq=0;
            }
        }
        if((currFreq+1)%k==0) ans+=(currFreq+1)*prev;
        return ans;
    }
};