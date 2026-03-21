// 3840. House Robber V
class Solution {
private:
    long long solve(vector<int>&nums,int start,int end){
        if((end-start+1)==1) return nums[start];
        if((end-start+1)==2) return max(nums[start],nums[end]);
        long long prev=nums[start],curr=max(nums[start],nums[start+1]);
        for(int i=start+2;i<=end;i++){
            long long temp=max(curr,1LL*(prev+nums[i]));
            prev=curr;
            curr=temp;
        }
        return curr;
    }
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int size=nums.size();
        long long profit=0;
        for(int i=0;i<size;i++){
            int j=i;
            while(j<size&&colors[i]==colors[j]){
                j++;
            }
            profit+=solve(nums,i,j-1);
            i=j-1;
        }
        return profit;
    }
};