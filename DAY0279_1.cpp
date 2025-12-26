// 3759. Count Elements With at Least K Greater Values
class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int size=nums.size();
        if(k>size) return 0;
        if(k==0) return size;
        // map<int,int>freq;
        // for(int num:nums) freq[num]++;
        // int freqSum=0;
        // for (auto it = freq.rbegin(); it != freq.rend(); ++it) {
        //     if (freqSum >= k) break;
        //     freqSum += it->second;
        // }
        // return size-freqSum;
        
        sort(nums.begin(),nums.end());
        int count=0;
        for(int num:nums){
            if(num<nums[size-k]) count++;
        }
        return count;
    }
};