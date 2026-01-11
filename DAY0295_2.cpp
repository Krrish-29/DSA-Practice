// 3804. Number of Centered Subarrays
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int count=0;
        set<int>set;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                set.insert(nums[j]);
                if(set.find(sum)!=set.end()) count++;
            }
            set.clear();
        }
        return count;
    }
};