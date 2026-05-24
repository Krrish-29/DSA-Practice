// 3940. Limit Occurrences in Sorted Array
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int size=nums.size(),curr,count,i=0,j=0;
        // for in place and constant space we can use two pointer 
        // if curr elem is seen we extend our search till either the number changes or the limit is reached
        // if the limit is reached then stop updating the j so that the already seen number can be replaced 
        // by future numbers and else number is changed then we start over and since c++ doesnt have 
        // split function for inplace we can simply use iterator for it
        for(;i<size;){
            curr=nums[i];
            count=0;
            while(i<size&&nums[i]==curr) {
                nums[j]=nums[i];
                count++;
                if(count<=k) j++;
                i++;
            }
        }
        vector<int>ans(nums.begin(),nums.begin()+j);
        return ans;
    }
};