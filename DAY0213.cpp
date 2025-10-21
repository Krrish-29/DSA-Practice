// 3346. Maximum Frequency of an Element After Performing Operations I
//try again very tough question (looks easy). 
// use normal freq and then do prefix freq sum at last check which elements can be converted to target with operations
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxEle=*max_element(nums.begin(),nums.end())+k;
        vector<int>freq(maxEle+1,0);
        for(int num:nums) freq[num]++;
        for(int i=1;i<=maxEle;i++) freq[i]+=freq[i-1];
        int res=0;
        for(int target=0;target<=maxEle;target++){
            if(freq[target]==0) continue;
            int left=max(0,target-k);
            int right=min(maxEle,target+k);
            int totalCount=freq[right]-(left>0?freq[left-1]:0);
            int targetCount=freq[target]-(target>0?freq[target-1]:0);
            res=max(res,targetCount+min(totalCount-targetCount,numOperations));
        }
        return res;
    }
};