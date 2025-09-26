// 611. Valid Triangle Number
class Solution {
private:
    int binary_search(vector<int>&nums,int left,int right,int target){
        int mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]<target) left=mid+1; 
            else right=mid-1;
        }
        return left;
    }
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0,size=nums.size();
        // n^2*logn solution
        // for(int i=0;i<size-2;i++){
        //     for(int j=i+1;j<size-1;j++){
        //         int k=binary_search(nums,j,size-1,nums[i]+nums[j]);
        //         if(k>j) count+=(k-j-1);
        //     }
        // }

        // n^2 solution
        int left,right;
        for(int i=size-1;i>1;i--){
            left=0;
            right=i-1;
            while(left<right){
                if(nums[right]+nums[left]>nums[i]){
                    count+=(right-left);
                    right--;
                }
                else left++;
            }
        }
        return count;
    }
};