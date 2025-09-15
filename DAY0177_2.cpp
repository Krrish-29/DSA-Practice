// 3684. Maximize Sum of At Most K Distinct Elements
class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),[](int a,int b){
            return a>b;
        });
        vector<int>total;
        int size=nums.size();
        int j=0;
        for(int i=0;i<size;i++){
            if(nums[j]!=nums[i]) {
                j++;
                nums[j]=nums[i];
            }
        }
        for(int i=0;i<k&&i<=j;i++){
            total.push_back(nums[i]);
        }
        return total;
    }
};