// 1608. Special Array With X Elements Greater Than or Equal X
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int left=0,right=nums.size(),mid;
        while(left<=right){
            mid=left+(right-left)/2;
            int count=0;
            for(int &num:nums){
                if(num>=mid) count++;
            }   
            if(count==mid) return mid;
            else if(count>mid) left=mid+1;
            else right=mid-1; 
        }
        return -1;
    }
};