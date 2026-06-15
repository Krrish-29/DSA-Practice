// 2161. Partition Array According to Given Pivot
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // or make 3 arrays and insert at the same time and combine at last 
        int size=nums.size();
        vector<int>ans;
        for(int i=0;i<size;i++){
            if(nums[i]<pivot) ans.push_back(nums[i]);
        }
        for(int i=0;i<size;i++){
            if(nums[i]==pivot) ans.push_back(nums[i]);
        }
        for(int i=0;i<size;i++){
            if(nums[i]>pivot) ans.push_back(nums[i]);
        }
        return ans;
    }
};