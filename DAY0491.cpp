// 628. Maximum Product of Three Numbers
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // the thing is if we did sort to maximize the product of 3 nums 
        // either we get the 3 highest elems or
        // we get the 2 smallest and 1 highest elem 

        int s1=INT_MAX,s2=INT_MAX,l1=INT_MIN,l2=INT_MIN,l3=INT_MIN;
        // l1 is highest +ve , l2 second highest +ve and l3 third highest +ve
        // s1 is smallest -ve , s2 second smallest -ve 
        for(int &num:nums){
            if(num>l1){
                l3=l2;
                l2=l1;
                l1=num;
            } 
            else if(num>l2){
                l3=l2;
                l2=num;
            } 
            else if(num>l3) {
                l3=num;
            }

            if(s1>num){
                s2=s1;
                s1=num;
            }
            else if(s2>num){
                s2=num;
            }
        }
        return max(l1*l2*l3,s1*s2*l1);

        // sort(nums.begin(),nums.end());
        // int size=nums.size()-1;
        // return max(nums[0]*nums[1]*nums[size],nums[size]*nums[size-1]*nums[size-2]);
    }
};