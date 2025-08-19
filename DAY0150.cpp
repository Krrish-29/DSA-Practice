// 2348. Number of Zero-Filled Subarrays
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long total=0;
        int n=0;
        for(int const num:nums){
            if(num==0) n++;
            else{
                total+=(1LL*n*(n+1)/2);
                n=0;
            }
        }
        total+=(1LL*n*(n+1)/2);
        return total;
    }
};