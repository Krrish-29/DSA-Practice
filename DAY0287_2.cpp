// 3795. Minimum Subarray Length With Distinct Sum At Least K
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int len=INT_MAX;
        int size=nums.size();
        unordered_map<int,int>map;
        int sum=0;
        for(int i=0,j=0;i<size;i++){
            map[nums[i]]++;
            if(map[nums[i]]==1) {
                sum+=nums[i];
            }
            while(sum>=k){
                len=min(len,i-j+1);
                map[nums[j]]--;
                if(map[nums[j]]==0){
                    sum-=nums[j];
                }
                j++;
            }
        }
        return len==INT_MAX?-1:len;
    }
};