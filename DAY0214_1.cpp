// 3347. Maximum Frequency of an Element After Performing Operations II
// try again its just a optimized version of 3346 using map to only store critical points
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxEle=*max_element(nums.begin(),nums.end())+k;
        map<int,int>diff;
        unordered_map<int,int>freq;
        for(int num:nums) {
            freq[num]++;
            diff[max(num-k,0)]++;
            diff[min(num+k,maxEle)+1]--;
            diff[num]+=0;
        }
        int res=1,sum=0;
        for(auto it=diff.begin();it!=diff.end();it++){
            int target=it->first;
            it->second+=sum;
            int targetCount=freq[target];
            int needConversion=it->second-targetCount;
            res=max(res,targetCount+min(needConversion,numOperations));
            sum=it->second;
        }
        return res;
    }
};
