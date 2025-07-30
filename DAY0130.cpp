// 2419. Longest Subarray With Maximum Bitwise AND
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int streak=0,maxval=0,total=0;
       for(int num:nums){
            if(num>maxval) {
                maxval=num;
                total=0;
                streak=0;
            }   
            if(maxval==num) streak++;
            else streak=0;
            total=max(total,streak);
        }
        return total; 


    // int size=nums.size(),max_val=0,len=0,maxlen=0;
    //     for(int i=0;i<size;i++){
    //         if(nums[i]>max_val){
    //             max_val=nums[i];
    //             maxlen=0;
    //             len=0;
    //         }
    //         if(nums[i]==max_val) {
    //             while(i<size&&nums[i]==max_val){
    //                 i++;
    //                 len++;
    //             }
    //             i--;
    //         }else{
    //             len=0;
    //         }
    //         maxlen=max(len,maxlen);
    //     }
    //     return maxlen;



    // int size=nums.size(),max_val=0,len=0,maxlen=0;
    // for(int i=0;i<size;i++){
    //     if(nums[i]>max_val){
    //         max_val=nums[i];
    //         maxlen=0;
    //         while(i<size&&nums[i]==max_val){
    //             i++;
    //             maxlen++;
    //         }
    //         i--;
    //     }
    //     else if(nums[i]==max_val) {
    //         while(i<size&&nums[i]==max_val){
    //             i++;
    //             len++;
    //         }
    //         maxlen=max(len,maxlen);
    //         i--;
    //     }
    //     len=0;
    // }
    // return maxlen;
    }
};