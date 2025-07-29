// 2411. Smallest Subarrays With Maximum Bitwise OR
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int size=nums.size(),reach;
        vector<int>answer(size,1);
        vector<int>bits(31,-1);
        for(int i=size-1;i>=0;i--){
            reach=i;
            for(int b=0;b<31;b++){
                if(nums[i]&(1<<b)) bits[b]=i;
                if(bits[b]!=-1) reach=max(reach,bits[b]);
            }
            answer[i]=reach-i+1;
        }
        return answer;
    }
};