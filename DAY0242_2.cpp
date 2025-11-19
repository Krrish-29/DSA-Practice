// 3745. Maximize Expression of Three Elements
class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int size=nums.size(),l1=INT_MIN,l2=INT_MIN,s1=INT_MAX;
        for(int i=0;i<size;i++){
            if(nums[i]>l1){
                l2=l1;
                l1=nums[i];
            }
            else if(nums[i]>l2){
                l2=nums[i];
            }
            s1=min(nums[i],s1);
        }
        return l1+l2-s1;
    }   
};