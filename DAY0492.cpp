// 1464. Maximum Product of Two Elements in an Array
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1=INT_MIN,max2=INT_MIN;
        for(int &num:nums){
            if(num>max1){
                max2=max1;
                max1=num;
            }
            else if(num>max2){
                max2=num;
            }
        }
        max1--;
        max2--;
        return max1*max2;
    }
};