// 3731. Find Missing Elements
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        map<int,int>map;
        int size=nums.size();
        int maxVal=INT_MIN,minVal=INT_MAX;
        for(int i=0;i<size;i++){
            maxVal=max(maxVal,nums[i]);
            minVal=min(minVal,nums[i]);
            map[nums[i]]++;
        }  
        vector<int>ans;
        for(int i=minVal;i<=maxVal;i++){
            if(map.find(i)==map.end()) ans.push_back(i);
        }
        return ans;
    }
};