// 31. Next Permutation
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k=-1,l=-1,size=nums.size();
        for(int i=0;i<size;i++){
            if(i+1<size&&nums[i]<nums[i+1]) k=i;
            if(k!=-1&&i>k&&nums[i]>nums[k]) l=i;
        }
        if(k!=-1&&l!=-1){
            swap(nums[k],nums[l]);
            for(int i=0;i<(size-k-1)/2;i++){
                swap(nums[i+k+1],nums[size-1-i]);
            }
            // reverse(nums.begin()+k+1,nums.end());
        }
        else{
            sort(nums.begin(),nums.end());
        }
    }
};