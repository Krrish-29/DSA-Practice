// 45. Jump Game II
class Solution {
public:
    int jump(vector<int>& nums) {
        int size=nums.size(),jump=0,maxjump,i=0;
        if(size==1) return 0;
        while(i<size){
            jump++;
            if(nums[i]+i>=size-1) break;
            maxjump=i+1;
            for(int j=i+2;j<nums[i]+1+i&&j<size;j++){
                if(nums[j]+j>=nums[maxjump]+maxjump) maxjump=j;
            }
            i=maxjump;
        }
        return jump;
    }
};