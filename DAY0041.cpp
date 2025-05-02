// 34. Find First and Last Position of Element in Sorted Array
class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int size=nums.size();
            vector<int> answer{-1,-1};
            int left=0,right=size-1;
            while(left<=right){
                int middle=left+(right-left)/2;
                if(nums[middle]==target){ 
                    answer[0]= middle;
                    answer[1]= middle;
                    right=middle-1;
                }
                else if (nums[middle]<target){ 
                    left=middle+1;
                }
                else{
                    right=middle-1;
                }
            }
            if(answer[0]==-1) return answer;
            left=answer[0]+1;right=size-1;
            while(left<=right){
                int middle=left+(right-left)/2;
                if(nums[middle]==target){
                    answer[1]=middle;
                    left=middle+1;
                }
                else if(nums[middle]<target){
                    left=middle+1;
                }
                else{
                    right=middle-1;
                }
            }
            return answer;
        }
    };