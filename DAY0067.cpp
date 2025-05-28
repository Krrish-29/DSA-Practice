// 215. Kth Largest Element in an Array
class Solution {
public:
    // int partition(vector<int>&nums,int start,int end){
    //     int pivot=nums[end];
    //     int i=start-1;
    //     for(int j=start;j<end;j++){
    //         if(nums[j]<pivot){
    //             i++;
    //             swap(nums[j],nums[i]);
    //         }
    //     }
    //     swap(nums[i+1],nums[end]);
    //     return i+1;
    // }
    // int quicksort(vector<int>&nums,int left,int right,int k){
    //     if(left<=right){
    //         int pivotIndex=partition(nums,left,right);
    //         if(k==pivotIndex) return  nums[k];
    //         else if(k<pivotIndex) return quicksort(nums,left,pivotIndex-1,k);
    //         else return quicksort(nums,pivotIndex+1,right,k);
    //     }
    //     return -1;
    // }
    int findKthLargest(vector<int>& nums, int k) {
        //quick select approach 
        // return quicksort(nums,0,nums.size()-1,nums.size()-k);


        //sorting appraoch 
        // sort(nums.begin(),nums.end());
        // return nums[nums.size()-k];

        // maxheap
        // priority_queue<int>heap;
        // for(auto num:nums) heap.push(num);
        // while(--k) heap.pop();
        // return heap.top();


        //max min element approach
        int max=INT_MIN,min=INT_MAX,size=nums.size();
        for(int i=0;i<size;i++){
            if(nums[i]>max) max=nums[i];
            if(nums[i]<min) min=nums[i];
        }
        vector<int>freq(max-min+1,0);
        for(int i=0;i<size;i++) freq[nums[i]-min]++;
        for(int i=max-min;i>=0;i--) {
            k-=freq[i];
            if(k<=0) return i+min; 
        }
        return -1;
    }
};