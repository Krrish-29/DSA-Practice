// 3824. Minimum K to Reduce Array Within Limit
class Solution {
private:
    bool isPossible(vector<int>&nums,int k){
        int count=0;
        for(int &num:nums){
            count+=(ceil((double)num/k));
        }
        return count<=(k*1LL*k);
    }
public:
    int minimumK(vector<int>& nums) {
        int left=1,right=100000,mid,ans;
        while(left<=right){
            mid=left+(right-left)/2;
            if(isPossible(nums,mid)){
                ans=mid;
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return ans;
    }
};