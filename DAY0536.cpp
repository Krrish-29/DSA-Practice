// 4044. Count Good Cyclic Rotations
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        // in the cyclic rotation one elem from left will move to the end 
        // this will make the leftHalf reduce by nums[0] and rightHalf increase by nums[0]
        // and the mid elem will also come in leftHalf from rightHalf as well
        // start by getting firstHalf and secondHalf 
        // then using (i+1)%size and (j+1)%size move the nums array and add and subtract nums[i]
        // and nums[j] accordingly 
        // time n and space 1
        int size = nums.size();
        long long firstHalf=0,secondHalf=0;
        int i=0,j=size/2;
        for(int x=0;x<size;x++){
            if(x<j) firstHalf+=nums[x];
            else secondHalf+=nums[x];
        }
        int count=0;
        for(int x=0;x<size;x++){
            if(firstHalf>secondHalf) count++;
            firstHalf+=(nums[j]-nums[i]);
            secondHalf+=(nums[i]-nums[j]);
            i = (i+1)%size;
            j = (j+1)%size;
        }
        return count;
    }
};