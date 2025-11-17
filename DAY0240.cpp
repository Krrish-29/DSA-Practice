// 1437. Check If All 1's Are at Least Length K Places Away
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int size=nums.size(),prev=-1e7;
        for(int i=0;i<size;i++){
            if(nums[i]==1){
                if(i-prev-1<k) return false;
                prev=i;
            }
        }   
        return true;
    }
};