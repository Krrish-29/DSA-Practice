// 1295. Find Numbers with Even Number of Digits
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int size=nums.size(),answer=0;
        for(int i=0;i<size;i++){
            int digits=0;
            while(nums[i]>0){
                digits++;
                nums[i]/=10;
            }
            if(digits%2==0) answer++;
        }
        return answer;
    }
};