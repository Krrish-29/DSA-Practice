// 3917. Count Indices With Opposite Parity
class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int size=nums.size();
        for(int i=0;i<size;i++){
            int parity=((nums[i]+1)%2);
            int score=0;
            for(int j=i+1;j<size;j++){
                if(nums[j]%2==parity) score++;
            }
            nums[i]=score;
        }
        return nums;
    }
};