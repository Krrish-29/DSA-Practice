// 167. Two Sum II - Input Array Is Sorted
class Solution {
private:
    int binary_search(vector<int>&nums,int left,int right,int target){
        int mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) right=mid-1;
            else left=mid+1;
        }
        return -1;
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size=numbers.size(),num2;
        for(int i=0;i<size-1;i++){
            num2=binary_search(numbers,i+1,size-1,target-numbers[i]);
            if(num2!=-1&&(numbers[i]+numbers[num2]==target)) return {i+1,num2+1};
        }
        return {};
    }
};