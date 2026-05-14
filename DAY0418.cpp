// 2934. Minimum Operations to Maximize Last Elements in Arrays
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int size=nums1.size();
        // if u see ele in nums1 <= nums1[size-1] and same for nums2 then keep moving on
        // or if we can swap and see if num1 <= nums2[size-1] and same for nums1 so add a operation
        // else its impossible 
        // do same after swapping nums1[size-1] and nums2[size-1]
        int op1=0;
        for(int i=0;i<size-1;i++){
            if(nums1[i]<=nums1[size-1]&&nums2[i]<=nums2[size-1]) continue;
            else if(nums1[i]<=nums2[size-1]&&nums2[i]<=nums1[size-1]) op1++;
            else return -1;
        }
        int op2=1;
        for(int i=0;i<size-1;i++){
            if(nums1[i]<=nums2[size-1]&&nums2[i]<=nums1[size-1]) continue;
            else if(nums1[i]<=nums1[size-1]&&nums2[i]<=nums2[size-1]) op2++;
            else return -1;
        }
        return min(op1,op2);
    }
};