// 1493. Longest Subarray of 1's After Deleting One Element
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxOne=INT_MIN,currOne=0,prevOne=0,size=nums.size();
        bool noZero=false;
        for(int num:nums){
            if(num==1){
                currOne++;
            }
            else{
                noZero=true;
                maxOne=max(maxOne,currOne+prevOne);
                prevOne=currOne;
                currOne=0;
            }
        }
        maxOne=max(maxOne,(currOne+prevOne));
        if(!noZero) maxOne-=1;
        return maxOne;
    }
};