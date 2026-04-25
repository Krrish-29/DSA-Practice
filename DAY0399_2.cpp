// 3909. Compare Sums of Bitonic Parts
class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
         int size=nums.size();
        long long asc=0,desc=0;
        int i=0;
        while(i+1<size&&nums[i]<nums[i+1]){
            asc+=nums[i];
            i++;
        }
        asc+=nums[i];
        while(i<size){
            desc+=nums[i];
            i++;
        }
        if(asc==desc) return -1;
        else if(asc>desc) return 0;
        else return 1;
    }
};