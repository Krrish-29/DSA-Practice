// 3354. Make Array Elements Equal to Zero
class Solution {
private:
    vector<int>prefixSum;
    vector<int>suffixSum;
    int size;
    int getDir(int idx){
        int left,right;
        if(idx==0){
            left=0;
        }
        else{
            left=prefixSum[idx-1];
        }
        if(idx==size-1){
            right=0;
        }
        else{
            right=suffixSum[idx+1];
        }
        if(left==right) return 2;
        if(abs(left-right)==1) return 1;
        return 0;
    }
public:
    int countValidSelections(vector<int>& nums) {
        size=nums.size();
        prefixSum.resize(size,0);
        suffixSum.resize(size,0);
        vector<int>zero;
        prefixSum[0]=nums[0];
        suffixSum[size-1]=nums[size-1];
        for(int i=0;i<size;i++){
            if(i>0) prefixSum[i]+=(prefixSum[i-1]+nums[i]);
            if(nums[i]==0) zero.push_back(i);
        }
        for(int i=size-2;i>=0;i--){
            suffixSum[i]+=(suffixSum[i+1]+nums[i]);
        }
        int count=0;
        for(int idx:zero){
            count+=getDir(idx);
        }
        return count;
    }
};