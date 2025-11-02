// 3732. Maximum Product of Three Elements After One Replacement
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int max1=INT_MIN,max2=INT_MIN;
        for(int num:nums){
            if(abs(num)>max1) {
                max2=max1;
                max1=abs(num);
            }
            else if(abs(num)>max2) max2=abs(num);
        }
        return 1LL*max1*max2*100000;
    }
};