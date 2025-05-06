// 1920. Build Array from Permutation
class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            int size=nums.size();
            vector<int>answer(size);
            for(int i=0;i<size;i++){
                answer[i]=nums[nums[i]];
            }
            return answer;
        }
    };