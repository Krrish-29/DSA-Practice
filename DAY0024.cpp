// 2006. Count Number of Pairs With Absolute Difference K
class Solution {
    public:
        int countKDifference(vector<int>& nums, int k) {
            int answer=0,size=nums.size();
            for(int i=0;i<size-1;i++){
                for(int j=i+1;j<size;j++){
                    if(abs(nums[i]-nums[j])==k) answer++;
                }
            }
            return answer;
        }
    };