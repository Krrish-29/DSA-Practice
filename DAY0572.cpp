// 2913. Subarrays Distinct Element Sum of Squares I
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        // can also use an bool array with intial false, and counting distinct
        // and marking true , instead of using a set
        int sum=0;
        for(int i=0;i<nums.size();i++){
            unordered_set<int>distinct;
            for(int j=i;j<nums.size();j++){
                distinct.insert(nums[j]);
                sum+= (distinct.size()*distinct.size());
            }    
        }
        return sum;
    }
};