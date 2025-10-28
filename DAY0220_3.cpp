// 1004. Max Consecutive Ones III
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int size=nums.size();
        int j=0;
        int maxSize=0;
        for(int i=0;i<size;i++){
            if(nums[i]==0) k--;
            while(j<=i&&k<0){
                if(nums[j]==0) k++;
                j++;
            }
            maxSize=max(maxSize,i-j+1);
        }
        return maxSize;
    }
};