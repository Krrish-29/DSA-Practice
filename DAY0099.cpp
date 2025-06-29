// 1498. Number of Subsequences That Satisfy the Given Sum Condition
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int size=nums.size(),left=0,right=size-1,answer=0,Mod=1e9+7;
        vector<int>powers(size,1);
        for(int i=1;i<size;i++){
            powers[i]=(powers[i-1]*2)%Mod;
        }
        while(left<=right){
            if(nums[left]+nums[right]<=target){
                answer=(long(answer+powers[right-left])%Mod);
                left++;
            }
            else{
                right--;
            }
        }
        vector<int>().swap(powers);
        return answer;
    }
};