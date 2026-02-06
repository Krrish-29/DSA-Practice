// 3634. Minimum Removals to Balance Array
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,j=0,len=INT_MAX,size=nums.size();
        while(j<size){
            if(nums[i]*1LL*k<nums[j]) i++;
            j++;
            len=min(len,size-j+i);
        }
        return len;
    }
};