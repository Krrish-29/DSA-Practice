// 962. Maximum Width Ramp
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int size=nums.size(),ramp=0;
        // get max for making the calculations easy 
        // as we will not look for right of i if there is not ele for condition satisfaction
        vector<int>maxRight(size,0);
        maxRight[size-1]=nums[size-1];
        for(int x=size-2;x>=0;x--){
            maxRight[x]=max(maxRight[x+1],nums[x]);
        }
        int i=0,j=1;
        while(j<size){
            while(i<j&&nums[i]>maxRight[j]) i++; 
            ramp=max(j-i,ramp);
            j++;
        }
        return ramp;
    }
};