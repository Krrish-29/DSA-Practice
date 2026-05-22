// 713. Subarray Product Less Than K
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // int size=nums.size(),product,count=0;
        // for(int i=0;i<size;i++){
        //     product=1;
        //     for(int j=i;j<size;j++){
        //         product*=nums[j];
        //         if(product<k) {
        //             count++;
        //         }
        //         else {
        //             break;
        //         }
        //     }
        // }
        // return count;

        int size=nums.size(),product=1,left=0,count=0;
        for(int right=0;right<size;right++){
            product*=nums[right];
            while(product>=k&&left<=right){
                product/=nums[left];
                left++;
            }
            count+=(right-left+1);
        }
        return count;
    }
};