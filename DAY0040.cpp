// 27. Remove Element
class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            // int size=nums.size();
            // for(int i=0;i<size;i++){
            //     if(nums[i]==val){
            //         nums.erase(nums.begin()+i);
            //         i--;
            //         size--;
            //     }
            // }
            // return size;
            int k=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=val){
                    nums[k]=nums[i];
                    k++;
                }
            }
            return k;
        }
    };