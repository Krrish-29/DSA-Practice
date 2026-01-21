// 3314. Construct the Minimum Bitwise Array I
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        //concept is that
        // x = 1 0 0 0 0 1 1 1
        // x+1=1 0 0 0 1 0 0 0
        // or =1 0 0 0 1 1 1 1 == let nums[i] 
        // so then how can we get the x the first time we see 0 bit moving from right to left
        // we need to make the j-1 bit to 0
        // 1 0 0 0 /1\ 1 1 1 ->1 0 0 0 1 1 1 == x
        int size=nums.size();
        for(int &num:nums){
            if(num==2) num=-1;
            else {
                int x=0;
                bool flag=false;
                for(int j=0;j<31;j++){
                    if(num&(1<<j)) x+=(1<<j);
                    else if(!flag){
                        x/=2;
                        flag=true;
                    }
                }
                num=x;
            }
        }
        return nums;
    }
};