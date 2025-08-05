// 3637. Trionic Array I
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool increase1=false,decrease=false,increase2=false;
        int size=nums.size(),i;
        for(i=1;i<size;i++){
            if(nums[i-1]>=nums[i]) break;
            increase1=true;
        }
        for(i;i<size;i++){
            if(nums[i-1]<=nums[i]) break;
            decrease=true;
        }
        for(i;i<size;i++){
            if(nums[i-1]>=nums[i]) break;
            increase2=true;
        }
        if(i==size&&increase1&&decrease&&increase2)return true;
        return false;
    }
};