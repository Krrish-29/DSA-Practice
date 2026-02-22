// 3847. Find the Score Difference in a Game
class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int p1=0,p2=0,size=nums.size();
        bool swap=false;
        for(int i=0;i<size;i++){
            if(nums[i]%2==1){
                swap=!swap;
            }
            if((i+1)%6==0){
                swap=!swap;
            }
            if(swap){
                p2+=nums[i];
            }
            else{
                p1+=nums[i];
            }
        }
        return p1-p2;
    }
};